COMPILER = gcc
FLAGS = -pedantic -Wall -fopenmp
OBJ = -c

PROGS = matrixMultiplicationOMP

all: matrixMultiplicationOMP

matrixMultiplicationOMP:
		$(COMPILER) $(FLAGS) $(OBJ) matrix.c
		$(COMPILER) $(FLAGS) $(OBJ) $@.c
		$(COMPILER) $(FLAGS) -o $@ $@.o matrix.o 

clean:
		$(RM) $(PROGS) *.o
