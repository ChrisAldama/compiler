TEST_NAME := test1

$(TEST_NAME): $(TEST_NAME).o $(OBJ) $(MUNIT_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	$(CURDIR)/$(TEST_NAME)

all: $(TEST_NAME)

clean:
	rm *.o

.PHONY: all