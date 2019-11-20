CC = gcc
SRC = main.c
CFLAGS = -Wall -Wextra -Werror

OBJ = $(subst .c, .o, $(SRC))

all:
	@$(CC) $(CFLAGC) $(SRC) libft.a
	@./a.out
