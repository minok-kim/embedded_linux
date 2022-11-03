# compile (preprocessing, compile, assembling)
cclient.o: cclient.c
	gcc -c cclient.c

# linking
all: cclient.o
	gcc -o cclient cclient.o 
	./cclient

run:
	./cclient

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
	rm -rf cclient
endif

