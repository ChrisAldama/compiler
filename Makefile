export TARGET := compi
export CC := gcc
export INC := -I$(CURDIR)/
export CFLAGS := -g -std=c99 $(INC)
export HEADERS := logic.h character.h scan.h token.h
export OBJ := $(CURDIR)/character.o $(CURDIR)/scan.o $(CURDIR)/token.o
export MUNIT_DIR := $(CURDIR)/munit
export MUNIT_OBJ := $(CURDIR)/munit.o

%.o: %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ) main.o
	$(CC) -o $@ $^ $(CFLAGS)

$(MUNIT_OBJ): $(MUNIT_DIR)/munit.c
	$(CC) -c -o $@ $^ $(CFLAGS)

tests: $(MUNIT_OBJ) $(TEST_FILES) $(OBJ)
	$(MAKE) all -C $(CURDIR)/tests

.PHONY: clean

clean:
	rm *.o
	$(MAKE) clean -C $(CURDIR)/tests

all: $(TARGET)
