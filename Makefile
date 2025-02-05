# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 17:59:51 by cauvray           #+#    #+#              #
#    Updated: 2025/02/05 18:32:13 by cauvray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INC_FLAGS	= -Iincludes -Ilibft/includes -Imlx/include

LIBFT_DIR	= libft
LIBFT_FILE	= libft.a
LIBFT_LIB	= $(addprefix $(LIBFT_DIR)/, $(LIBFT_FILE))

# TODO: Redo
MLX_DIR		= mlx
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

lib:
	@echo "$(INFO) Compiling $(LIBFT_DIR)...$(GRAY)"
	@make -C $(LIBFT_DIR)
	@echo "$(SUCCESS) $(LIBFT_DIR) compiled."

mlx:
	@echo "$(INFO) Compiling $(MLX_DIR)...$(GRAY)"
	cmake -S mlx42_src -B mlx42
	make -C mlx42
	@echo "$(SUCCESS) $(MLX_DIR) compiled."

$(NAME): lib mlx $(OBJS)
	@echo "$(INFO) Compiling $(NAME)...$(GRAY)"
	$(CC) $(CFLAGS) $(INC_FLAGS) $(LIBFT_LIB) $(MLX_EX) $(OBJS) -o $@
	@echo "$(SUCCESS) $(NAME) compiled."

clean:
	@echo "$(INFO) Removing $(MLX_DIR)...$(GRAY)"
	rm -rf $(MLX_DIR)
	@echo "$(INFO) Removing $(LIBFT_DIR)...$(GRAY)"
	rm -rf $(LIBFT_DIR)
	@echo "$(INFO) Removing $(NAME) object files...$(GRAY)"
	rm -rf $(OBJS_DIR)
	@echo "$(SUCCESS) Objects and libs removed."

fclean: clean
	@echo "$(INFO) Removing $(NAME)...$(GRAY)"
	rm -f $(NAME)
	@echo "$(SUCCESS) $(NAME) removed."

re: fclean all

.PHONY: all lib mlx clean fclean re
