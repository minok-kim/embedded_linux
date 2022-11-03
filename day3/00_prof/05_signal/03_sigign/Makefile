# compile (preprocessing, compile, assembling)
exec4.o: exec4.c
	gcc -c exec4.c

# linking
all: exec4.o
	gcc -o exec4 exec4.o 
	./exec4 sleep 5

run:
	./exec4 sleep 5

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
	rm -rf exec4
endif

