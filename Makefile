# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/15 18:59:34 by sdavi-al          #+#    #+#              #
#    Updated: 2025/02/18 17:16:29 by sdavi-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRC =	src/calculate_costs.c \
		src/handle_stack.c \
		src/indices_and_target.c \
		src/main.c \
		src/main_loop.c \
		src/push.c \
		src/push_initial_nodes.c \
		src/reverse_rotate.c \
		src/rotate.c \
		src/small_stacks.c \
		src/swap.c \
		src/validate_args.c \
		src/b_to_a.c
			
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
