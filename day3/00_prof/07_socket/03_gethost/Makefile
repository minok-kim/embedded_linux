# compile (preprocessing, compile, assembling)
gethost.o: gethost.c
	gcc -c gethost.c

# linking
all: gethost.o
	gcc -o gethost gethost.o 
	./gethost www.naver.com

run:
	./gethost www.naver.com

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
	rm -rf gethost
endif

