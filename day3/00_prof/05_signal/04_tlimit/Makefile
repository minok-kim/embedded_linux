# compile (preprocessing, compile, assembling)
tlimit.o: tlimit.c
	gcc -c tlimit.c

# linking
all: tlimit.o
	gcc -o tlimit tlimit.o 
	./tlimit 3 sleep 5

run:
	./tlimit 3 sleep 5

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
	rm -rf tlimit
endif

