NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC =	src/push_swap.c \
		src/stack_utils.c \
		src/validation.c \
		src/utils.c \
		src/ope1.c \
		src/ope2.c \
		src/ope3.c \
		src/ope4.c \
		src/algo.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
