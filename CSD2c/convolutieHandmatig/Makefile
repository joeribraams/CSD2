CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++17
LDFLAGS= -ljack

all: example

example : main.o fir.o
	$(CC) -o $@ $(CFLAGS) main.o fir.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
