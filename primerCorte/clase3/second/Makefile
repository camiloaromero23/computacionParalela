GCC = gcc
FLAGS = -ansi -pedantic -Wall
OBJ = -c

CFLAGS = -lm

PROGS = second

all: second

second:
		$(GCC) $(FLAGS) $(OBJ) functions.c
		$(GCC) $(FLAGS) $(OBJ) $@.c
		$(GCC) $(FLAGS) -o $@ $@.o functions.o 

clean:
		$(RM) $(PROGS) *.o
