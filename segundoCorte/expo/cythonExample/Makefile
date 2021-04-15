COMPILER = python3
FLAGS = build_ext --inplace

SETUP = setup

all: $(SETUP)

$(SETUP):
		$(COMPILER) $@.py $(FLAGS) 
		
clean:
		rm -rf *.so *.c *.html build
