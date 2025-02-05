# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 14:56:43 by cauvray           #+#    #+#              #
#    Updated: 2024/11/29 08:53:24 by cauvray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar
AR_FLAGS	= rcs

GNL_FILES		= get_next_line.c
IS_FILES		= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
				ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c
LST_FILES		= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
				ft_lstdelone.c ft_lstget.c ft_lstiter.c ft_lstlast.c \
				ft_lstiter_param.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
MEM_FILES		= ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
				ft_memmove.c ft_memset.c
PRINTF_FILES	= ft_hex_utils.c ft_int_utils.c ft_printf_utils.c \
				ft_params_utils.c ft_printf_params.c ft_printf_c.c \
				ft_printf_s.c ft_printf_id.c ft_printf_x.c ft_printf_u.c \
				ft_printf_p.c ft_printf.c
PUT_FILES		= ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c
STR_FILES		= ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
				ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
				ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
				ft_strtrim.c ft_substr.c ft_strndup.c ft_strrev.c ft_nbrlen.c
TO_FILES		= ft_atoi.c ft_atol.c ft_itoa.c ft_tolower.c ft_toupper.c

ALL_FILES	= $(GNL_FILES) $(IS_FILES) $(LST_FILES) $(MEM_FILES) \
			$(PRINTF_FILES) $(PUT_FILES) $(STR_FILES) $(TO_FILES)

SRCS_DIR	= srcs
OBJS_DIR	= objs
OBJS_FILES	= $(ALL_FILES:.c=.o)
OBJS		= $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

INC_DIR		= includes
INC_FLAGS	= -I $(INC_DIR)

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

$(OBJS_DIR)/%.o: $(SRCS_DIR)/*/%.c | $(OBJS_DIR)
	@echo "$(INFO) Compiling $<...$(GRAY)"
	$(CC) $(CFLAGS) -c $(INC_FLAGS) $< -o $@

$(NAME): $(OBJS)
	@echo "$(INFO) Creating $(NAME)...$(GRAY)"
	$(AR) $(AR_FLAGS) $@ $^
	@echo "$(SUCCESS) $(NAME) created successfully!"

clean:
	@echo "$(INFO) Removing object files...$(GRAY)"
	rm -rf $(OBJS_DIR)
	@echo "$(SUCCESS) Objects removed."

fclean: clean
	@echo "$(INFO) Removing $(NAME)...$(GRAY)"
	rm -f $(NAME)
	@echo "$(SUCCESS) $(NAME) removed."

re: fclean all

.PHONY: all clean fclean re
