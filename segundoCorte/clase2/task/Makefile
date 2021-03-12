COMPILER = gcc
FLAGS = -pedantic -Wall -fopenmp
OBJ = -c

CONVENTIONAL = conventionalMatrixMultiplicationOMP
TRANSPOSE = transposeMatrixMultiplicationOMP

PROGS = $(CONVENTIONAL) $(TRANSPOSE)

all: modules $(CONVENTIONAL) $(TRANSPOSE)

modules:
		$(COMPILER) $(FLAGS) $(OBJ) matrix.c

$(CONVENTIONAL):
		$(COMPILER) $(FLAGS) $(OBJ) $(CONVENTIONAL).c
		$(COMPILER) $(FLAGS) -o $(CONVENTIONAL) $(CONVENTIONAL).o matrix.o 
		
$(TRANSPOSE):
		$(COMPILER) $(FLAGS) $(OBJ) $(TRANSPOSE).c
		$(COMPILER) $(FLAGS) -o $(TRANSPOSE) $(TRANSPOSE).o matrix.o 

clean:
		$(RM) $(PROGS) *.o
