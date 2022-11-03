# compile (preprocessing, compile, assembling)
signal.o: signal.c
	gcc -c signal.c

# linking
all: signal.o
	gcc -o signal signal.o -lm
	sudo ./signal

run:
	sudo ./signal

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
	rm -rf signal
endif

