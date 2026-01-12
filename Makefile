SRC_S = server.c \
	./printf/ft_printf.c \
	./printf/ft_putnbr_base.c \
	./printf/ft_putstr_fd.c \
	./printf/ft_specifier.c \
	./printf/print.c \

SRC_C = client.c

OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)

CC = cc
FLAG = -Wall -Werror -Wextra -g

PRTF = -I./printf

all: server client

server: $(OBJ_S)
	$(CC) $(FLAG) $(OBJ_S) -o server

client: $(OBJ_C)
	$(CC) $(FLAG) $(OBJ_C) -o client

%.o: %.c
	$(CC) $(FLAG) $(PRTF) -c $< -o $@

clean:
	rm -f $(OBJ_S) $(OBJ_C)

fclean: clean
	rm -f server

re: fclean all

.PHONY: all clean fclean re