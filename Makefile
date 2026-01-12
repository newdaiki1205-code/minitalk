SRC_S = server.c ft_atoi.c \
	./printf/ft_printf.c \
	./printf/ft_putnbr_base.c \
	./printf/ft_putstr_fd.c \
	./printf/ft_specifier.c \
	./printf/print.c \

SRC_C = client.c ft_atoi.c\
	./printf/ft_printf.c \
	./printf/ft_putnbr_base.c \
	./printf/ft_putstr_fd.c \
	./printf/ft_specifier.c \
	./printf/print.c \

SRC_SB = server_bonus.c ft_atoi.c\
	./printf/ft_printf.c \
	./printf/ft_putnbr_base.c \
	./printf/ft_putstr_fd.c \
	./printf/ft_specifier.c \
	./printf/print.c \

SRC_CB = client_bonus.c ft_atoi.c\
	./printf/ft_printf.c \
	./printf/ft_putnbr_base.c \
	./printf/ft_putstr_fd.c \
	./printf/ft_specifier.c \
	./printf/print.c \


OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)
OBJ_SB = $(SRC_SB:.c=.o)
OBJ_CB = $(SRC_CB:.c=.o)

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

bonus: server_bonus client_bonus

server_bonus: $(OBJ_SB)
	$(CC) $(FLAG) $(OBJ_SB) -o server_bonus

client_bonus: $(OBJ_CB)
	$(CC) $(FLAG) $(OBJ_CB) -o client_bonus

clean:
	rm -f $(OBJ_S) $(OBJ_C) $(OBJ_SB) $(OBJ_CB)

fclean: clean
	rm -f server client server_bonus client_bonus

re: fclean all

.PHONY: all clean fclean re