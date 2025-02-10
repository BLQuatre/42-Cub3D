# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 17:59:51 by cauvray           #+#    #+#              #
#    Updated: 2025/02/13 03:09:13 by cauvray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -pthread
LFLAGS		= -ldl -lglfw -lm

INC_DIR		= includes
INC_FLAGS	= -I$(INC_DIR) -Ilibft/$(INC_DIR) -I$(INC_DIR)/MLX42

LIB_GIT_URL	= https://github.com/BLQuatre/42-my_libft.git
LIB_DIR		= libft
LIB_FILE	= libft.a
LIB_LIB		= $(LIB_DIR)/$(LIB_FILE)

MLX_GIT_URL	= https://github.com/codam-coding-college/MLX42.git
MLX_SRC_DIR	= mlx42_src
MLX_INC_DIR	= $(MLX_SRC_DIR)/include/MLX42
MLX_DIR		= mlx42
MLX_FILE	= libmlx42.a
MLX_LIB		= $(MLX_DIR)/$(MLX_FILE)

RAW_FILES	=	debug/debug debug/vector debug/map debug/game debug/color	\
				\
				utils/arrays utils/colors 									\
				\
				structs/game structs/map									\
				\
				parsing/colors parsing/game parsing/map_check				\
				parsing/map_utils parsing/map parsing/textures_errors		\
				parsing/textures parsing/utils								\
				\
				render/render render/exit render/hook render/main render/ray render/rendering \
				\
				core/cub3d core/errors

FILES		= $(addsuffix .c, $(RAW_FILES))

SRCS_DIR	= srcs
OBJS_DIR	= objs
OBJS_FILES	= $(FILES:.c=.o)
OBJS		= $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

GREEN		= \033[0;32m
CYAN		= \033[0;36m
RESET		= \033[0m
GRAY		= \033[90m

SUCCESS		= $(GREEN)[SUCCESS]$(RESET)
INFO		= $(CYAN)[INFO]$(RESET)

WIN_SIZE	= \
	-D WIN_WIDTH=$$(xrandr --current | grep '*' | head -n1 | awk '{print $$1}' | cut -d 'x' -f1) \
	-D WIN_HEIGHT=$$(xrandr --current | grep '*' | head -n1 | awk '{print $$1}' | cut -d 'x' -f2)

all: $(NAME)

$(OBJS_DIR):
	@if [ ! -d ./$(OBJS_DIR) ]; then \
		echo "$(INFO) Creating $(OBJS_DIR) directory..."; \
		echo "$(GRAY)mkdir -p $(OBJS_DIR)"; \
		mkdir -p $(OBJS_DIR); \
	fi

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	mkdir -p $(dir $@)
	@echo "$(INFO) Compiling $<...$(GRAY)"
	$(CC) $(WIN_SIZE) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

$(LIB_LIB):
	@if [ -d ./$(LIB_DIR) ]; then	\
		rm -rf $(LIB_DIR);			\
	fi

	@echo "$(INFO) Compiling $(LIB_DIR)...$(GRAY)"
	git clone $(LIB_GIT_URL) $(LIB_DIR)
	make -C $(LIB_DIR) -j $$(nproc)
	@echo "$(SUCCESS) $(LIB_DIR) compiled."

$(MLX_LIB):
	@if [ -d ./$(MLX_SRC_DIR) ]; then	\
		rm -rf $(MLX_SRC_DIR);			\
	fi

	@if [ ! -d ./$(MLX_DIR) ]; then						\
		echo "$(INFO) Compiling $(MLX_DIR)...$(GRAY)";	\
		git clone $(MLX_GIT_URL) $(MLX_SRC_DIR);		\
		cmake -S $(MLX_SRC_DIR) -B $(MLX_DIR);			\
		make -C $(MLX_DIR) -j $$(nproc);				\
		cp -r $(MLX_INC_DIR) $(INC_DIR);				\
		rm -rf  $(MLX_SRC_DIR);							\
		echo "$(SUCCESS) $(MLX_DIR) compiled.";			\
	fi

$(NAME): $(LIB_LIB) $(MLX_LIB) $(OBJS)
	@echo "$(INFO) Compiling $(NAME)...$(GRAY)"
	$(CC) $(WIN_SIZE) $(CFLAGS) $(INC_FLAGS) $(OBJS) $(LIB_LIB) $(MLX_LIB) $(LFLAGS) -o $@
	@echo "$(SUCCESS) $(NAME) compiled."

clean:
	@echo "$(INFO) Removing $(MLX_DIR)...$(GRAY)"
	rm -rf $(MLX_DIR)
	rm -rf $(INC_DIR)/MLX42
	@echo "$(INFO) Removing $(LIB_DIR)...$(GRAY)"
	rm -rf $(LIB_DIR)
	@echo "$(INFO) Removing object files...$(GRAY)"
	rm -rf $(OBJS_DIR)
	@echo "$(SUCCESS) Objects and libs removed."

fclean: clean
	@echo "$(INFO) Removing $(NAME)...$(GRAY)"
	rm -f $(NAME)
	@echo "$(SUCCESS) $(NAME) removed."

re: fclean all

.PHONY: all clean fclean re
