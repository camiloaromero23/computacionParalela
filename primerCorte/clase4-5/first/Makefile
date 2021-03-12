COMPILER = gcc
FLAGS = -pedantic -Wall
OBJ = -c

PROGS = task

all: task

task:
		$(COMPILER) $(FLAGS) $(OBJ) matrix.c
		$(COMPILER) $(FLAGS) $(OBJ) $@.c
		$(COMPILER) $(FLAGS) -o $@ $@.o matrix.o 

clean:
		$(RM) $(PROGS) *.o
