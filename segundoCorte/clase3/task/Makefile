# 
# UNIVERSIDAD SERGIO ARBOLEDA
# ESCUELA DE CIENCIAS EXACTAS E INGENIERÍA
# INGENIERÍA DE SISTEMAS Y TELECOMUNICACIONES
# 
# AUTHORS: JUAN JOSÉ MONTENEGRO PULIDO & CAMILO ANDRÉS ROMERO MALDONADO
# EMAILS: juan.montenegro@correo.usa.edu.co & camiloa.romero@correo.usa.edu.co
# 
# 12/03/2021
# 

COMPILER = gcc
FLAGS = -pedantic -Wall -fopenmp
OBJ = -c

CONVENTIONAL = MM1c
CONVENTIONAL_DYNAMIC = MM1cDynamic
CONVENTIONAL_DYNAMIC_NO_FUNCTIONS = MM1cDynamicNoFunctions
TRANSPOSE = MM1f
TRANSPOSE_DYNAMIC = MM1fDynamic
TRANSPOSE_DYNAMIC_NO_FUNCTIONS = MM1fDynamicNoFunctions

PROGS = $(CONVENTIONAL) $(TRANSPOSE) $(CONVENTIONAL_DYNAMIC) $(TRANSPOSE_DYNAMIC) $(CONVENTIONAL_DYNAMIC_NO_FUNCTIONS) $(TRANSPOSE_DYNAMIC_NO_FUNCTIONS)

all: $(PROGS)

$(CONVENTIONAL):
		$(COMPILER) $(FLAGS) $(OBJ) matrix.c
		$(COMPILER) $(FLAGS) $(OBJ) $@.c
		$(COMPILER) $(FLAGS) -o $@ $@.o matrix.o 
		
$(TRANSPOSE):
		$(COMPILER) $(FLAGS) $(OBJ) matrix.c
		$(COMPILER) $(FLAGS) $(OBJ) $@.c
		$(COMPILER) $(FLAGS) -o $@ $@.o matrix.o 

$(CONVENTIONAL_DYNAMIC):
		$(COMPILER) $(FLAGS) $(OBJ) matrix.c
		$(COMPILER) $(FLAGS) $(OBJ) $@.c
		$(COMPILER) $(FLAGS) -o $@ $@.o matrix.o 

$(TRANSPOSE_DYNAMIC):
		$(COMPILER) $(FLAGS) $(OBJ) matrix.c
		$(COMPILER) $(FLAGS) $(OBJ) $@.c
		$(COMPILER) $(FLAGS) -o $@ $@.o matrix.o 

$(CONVENTIONAL_DYNAMIC_NO_FUNCTIONS):
		$(COMPILER) $(FLAGS) $(OBJ) matrix.c
		$(COMPILER) $(FLAGS) $(OBJ) $@.c
		$(COMPILER) $(FLAGS) -o $@ $@.o matrix.o 

$(TRANSPOSE_DYNAMIC_NO_FUNCTIONS):
		$(COMPILER) $(FLAGS) $(OBJ) matrix.c
		$(COMPILER) $(FLAGS) $(OBJ) $@.c
		$(COMPILER) $(FLAGS) -o $@ $@.o matrix.o 

clean:
		$(RM) $(PROGS) *.o
