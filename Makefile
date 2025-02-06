# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 17:59:51 by cauvray           #+#    #+#              #
#    Updated: 2025/02/06 13:54:37 by cauvray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INC_FLAGS	= -Iincludes -Ilibft/includes -Imlx/include

LIB_GIT_URL	= https://github.com/BLQuatre/42-my_libft.git
LIB_DIR		= libft
LIB_FILE	= libft.a
LIB_LIB		= $(addprefix $(LIB_DIR)/, $(LIB_FILE))

MLX_GIT_URL	= https://github.com/codam-coding-college/MLX42.git
MLX_SRC_DIR	= mlx42_src
MLX_DIR		= mlx42
MLX_FILE	= libmlx42.a
MLX_LIB		= $(addprefix $(MLX_DIR)/, $(MLX_FILE))
MLX_FLAG	= -ldl -lglfw -pthread -lm
MLX_EX		= $(MLX_LIB) $(MLX_FLAG)

RAW_FILES	= core/cub3d

FILES		= $(addsuffix .c, $(RAW_FILES))

SRCS_DIR	= srcs
OBJS_DIR	= objs
OBJS_FILES	= $(FILES:.c=.o)
OBJS		= $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

GREEN	= \033[0;32m
CYAN	= \033[0;36m
RESET	= \033[0m
GRAY	= \033[90m

SUCCESS	= $(GREEN)[SUCCESS]$(RESET)
INFO	= $(CYAN)[INFO]$(RESET)

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
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

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
		rm -rf  $(MLX_SRC_DIR);							\
		echo "$(SUCCESS) $(MLX_DIR) compiled.";			\
	fi

$(NAME): $(LIB_LIB) $(MLX_LIB) $(OBJS)
	@echo "$(INFO) Compiling $(NAME)...$(GRAY)"
	$(CC) $(CFLAGS) $(INC_FLAGS) $(LIB_LIB) $(MLX_EX) $(OBJS) -o $@
	@echo "$(SUCCESS) $(NAME) compiled."

clean:
	@echo "$(INFO) Removing $(MLX_DIR)...$(GRAY)"
	rm -rf $(MLX_DIR)
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

.PHONY: all lib mlx clean fclean re
