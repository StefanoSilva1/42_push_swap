NAME    = push_swap

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRC     =	src/main.c \
			src/handle_stack.c \
			src/validate_args.c \
			src/swap.c \
			src/push.c \
			src/rotate.c \
			src/reverse_rotate.c
			
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
