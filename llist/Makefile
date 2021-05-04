CC=gcc
CFLAGS=-g -pedantic -Wall

all: quack 

quack: quack.o stack.o queue.o llist.o
	$(CC) $(CFLAGS) -o $@ $^

quack.o: quack.c stack.h

stack.o: stack.c stack.h llist.h

queue.o: queue.c queue.h llist.h

llist.o: llist.c llist.h

clean:
	$(RM) quack *.o
