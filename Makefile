NAME = get_next_line.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRC = get_next_line.c get_next_line_utils.c main.c
BONUS_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

program: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@


bonus: $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

%.o : %.c get_next_line.h get_next_line_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) program

fclean: clean
	rm -f $(NAME)

re: clean program