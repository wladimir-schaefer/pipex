NAME = pipex
SRC  = main.c utils_1.c utils_2.c
OBJ  = $(SRC:.c=.o)

NAME_BONUS = pipex_bonus
SRC_BONUS  = main_bonus.c utils_1_bonus.c utils_2_bonus.c
OBJ_BONUS  = $(SRC_BONUS:.c=.o)

# Paths
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# Compiler & flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g -I$(LIBFT_DIR)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(OBJ) $(LIBFT_LIB) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT_LIB)
	$(CC) $(OBJ_BONUS) $(LIBFT_LIB) -o $(NAME_BONUS)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean re