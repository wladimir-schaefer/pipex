NAME    = pipex
SRC     = main.c
OBJ     = $(SRC:.c=.o)

# Paths
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# Compiler & flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(OBJ) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean re