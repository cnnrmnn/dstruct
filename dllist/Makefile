CC=gcc
CFLAGS=-g -pedantic -Wall

all: bin quack

quack: quack.o deque.o dllist.o 
	$(CC) $(CFLAGS) -o ./bin/$@ $^

quack.o: quack.c deque.h

deque.o: deque.c deque.h dllist.h 

dllist.o: dllist.c dllist.h

bin:
	mkdir bin

clean:
	rm -rf bin *.o
