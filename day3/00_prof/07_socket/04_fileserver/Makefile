# compile (preprocessing, compile, assembling)
fserver.o: fserver.c
	gcc -c fserver.c

fclient.o: fclient.c
	gcc -c fclient.c

# linking
all: fserver.o fclient.o
	gcc -o fserver fserver.o 
	gcc -o fclient fclient.o 

	./fserver 5000 &
	./fclient 169.254.194.54 5000

run:
	./fserver 5000 &
	./fclient 169.254.194.54 5000

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
	rm -rf fserver fclient
endif

