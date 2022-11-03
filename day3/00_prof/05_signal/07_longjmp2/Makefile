# compile (preprocessing, compile, assembling)
jump2.o: jump2.c
	gcc -c jump2.c

# linking
all: jump2.o
	gcc -o jump2 jump2.o 
	./jump2

run:
	./jump2

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
	rm -rf jump2
endif

