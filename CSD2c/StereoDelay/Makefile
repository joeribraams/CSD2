CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++17
LDFLAGS= -ljack

all: example

example : jack_module.o circBuffer.o main.o stereoDelay.o sine.o
	$(CC) -o $@ $(CFLAGS) jack_module.o circBuffer.o main.o stereoDelay.o sine.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
