CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC = main.c sorts.c
OBJ = $(SRC:.c=.o)
NAME = energy_explorer

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) data.csv

re: fclean all
