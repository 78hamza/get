NAME = get_next_line.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRC = get_next_line.c get_next_line_utils.c main.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

program: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) program

fclean: clean
	rm -f $(NAME)

re: clean program