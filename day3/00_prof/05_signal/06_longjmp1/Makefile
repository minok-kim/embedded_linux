# compile (preprocessing, compile, assembling)
jump1.o: jump1.c
	gcc -c jump1.c

# linking
all: jump1.o
	gcc -o jump1 jump1.o 
	./jump1

run:
	./jump1

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
	rm -rf jump1
endif

