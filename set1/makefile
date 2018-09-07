CC=gcc
CFLAGS=-I. -g -Wsign-conversion
DEPS = common.h
OBJ = common.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: challenge1 challenge2

challenge1: $(OBJ) challenge1.o
	$(CC) -o $@ $^ $(CFLAGS)

challenge2: $(OBJ) challenge2.o
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o challenge1 challenge2
