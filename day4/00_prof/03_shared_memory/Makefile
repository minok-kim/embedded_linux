# compile (preprocessing, compile, assembling)
shm.o: shm.c
	gcc -c shm.c

# linking
all: shm.o
	gcc -o shm shm.o -lm
	sudo ./shm

run:
	sudo ./shm

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
	rm -rf shm
endif

