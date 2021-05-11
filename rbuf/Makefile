CC=gcc
CFLAGS=-g -pedantic -Wall

all: bin btrbuf

btrbuf: btrbuf.o rbuf.o
	$(CC) $(CFLAGS) -o ./bin/$@ $^

btrbuf.o: btrbuf.c rbuf.h

rbuf.o: rbuf.c rbuf.h

bin:
	mkdir bin

clean:
	rm -rf bin *.o
