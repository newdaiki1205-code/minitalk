NAME = server

SRC = server.c \
	./printf/ft_printf.c \
	./printf/ft_putnbr_base.c \
	./printf/ft_putstr_fd.c \
	./printf/ft_specifier.c \
	./printf/print.c \

OBJ = $(SRC:.c=.o)

CC = cc
FLAG = -Wall -Werror -Wextra -g

PRTF = -I./printf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAG) $(PRTF) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re