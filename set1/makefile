CC=gcc
CFLAGS=-I. -g -Wsign-conversion -Wreturn-type
DEPS = common.h
OBJ = common.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: challenge1 challenge2 challenge3 challenge4 challenge5 challenge6

# there's probably a more clever way to do this

challenge1: $(OBJ) challenge1.o
	$(CC) -o $@ $^ $(CFLAGS)

challenge2: $(OBJ) challenge2.o
	$(CC) -o $@ $^ $(CFLAGS)

challenge3: $(OBJ) challenge3.o
	$(CC) -o $@ $^ $(CFLAGS)

challenge4: $(OBJ) challenge4.o
	$(CC) -o $@ $^ $(CFLAGS)

challenge5: $(OBJ) challenge5.o
	$(CC) -o $@ $^ $(CFLAGS)

challenge6: $(OBJ) challenge6.o
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o challenge1 challenge2 challenge3 challenge4 challenge5 challenge6
