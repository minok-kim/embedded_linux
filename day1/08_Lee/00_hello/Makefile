help:
	@echo "make help"
	@echo "make all"

# pre-processing only


# compilation only
# define

# assembling only


# all preprocessing, compiling, assembling.
#main.o: main.c
#	gcc -c main.c

foo.o: 

all: 
	gcc -o main 
	./main


clean: 
ifeq ($(OS),Windows_NT)
	del *.o *.i *.s
else
	rm -rf *.o *.i *.s
endif

cleanup: clean
ifeq ($(OS),Windows_NT)
	del *.exe	
else
	rm -rf main
endif

	

