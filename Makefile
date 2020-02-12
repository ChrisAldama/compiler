TARGET=compi
CC=gcc
CFLAGS=-g -std=c99
HEADERS=logic.h character.h scan.h token.h
OBJ=character.o main.o scan.o token.o

%.o: %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm *.o

all: $(TARGET)
