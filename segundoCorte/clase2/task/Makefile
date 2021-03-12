COMPILER = gcc
FLAGS = -pedantic -Wall -fopenmp
OBJ = -c

TRANSPOSE = transposeMatrixMultiplicationOMP

PROGS = conventionalMatrixMultiplicationOMP $(TRANSPOSE)

all: conventionalMatrixMultiplicationOMP

conventionalMatrixMultiplicationOMP:
		$(COMPILER) $(FLAGS) $(OBJ) matrix.c
		$(COMPILER) $(FLAGS) $(OBJ) $@.c
		$(COMPILER) $(FLAGS) -o $@ $@.o matrix.o 
		$(COMPILER) $(FLAGS) $(OBJ) $(TRANSPOSE).c
		$(COMPILER) $(FLAGS) -o $(TRANSPOSE) $(TRANSPOSE).o matrix.o 

clean:
		$(RM) $(PROGS) *.o
