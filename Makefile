# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 12:39:45 by sdavi-al          #+#    #+#              #
#    Updated: 2025/02/11 14:07:58 by sdavi-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRC     =	src/main.c \
			src/process_args.c \
			src/append_node.c \
			src/swap.c \
			src/push.c \
			src/rotate.c \
			src/reverse_rotate.c \
			src/cleanup.c
			
LIBFT_DIR = libft
LIBFT   = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(SRC)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -o $(NAME) $(SRC) $(LIBFT)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
