# compile (preprocessing, compile, assembling)
cserver.o: cserver.c
	gcc -c cserver.c

# linking
all: cserver.o
	gcc -o cserver cserver.o 
	./cserver &

run:
	./cserver &

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
	rm -rf cserver convert
endif

