# compile (preprocessing, compile, assembling)
sigint1.o: sigint1.c
	gcc -c sigint1.c

# linking
all: sigint1.o
	gcc -o sigint1 sigint1.o 
	./sigint1

run:
	./sigint1

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
	rm -rf sigint1
endif

