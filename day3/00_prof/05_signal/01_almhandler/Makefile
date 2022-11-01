# compile (preprocessing, compile, assembling)
almhandler.o: almhandler.c
	gcc -c almhandler.c

# linking
all: almhandler.o
	gcc -o almhandler almhandler.o 
	./almhandler

run:
	./almhandler

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
	rm -rf almhandler
endif

