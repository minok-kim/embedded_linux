# compile (preprocessing, compile, assembling)
control.o: control.c
	gcc -c control.c

# linking
all: control.o
	gcc -o control control.o 
	./control

run:
	./control

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
	rm -rf control
endif

