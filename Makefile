CC = gcc
SRC = pr_val.c functions1.c
CFLAGS = -Wall -Wextra -Werror

OBJ = $(subst .c, .o, $(SRC))

all:
	@$(CC) $(CFLAGC) $(SRC)
	@./a.out
