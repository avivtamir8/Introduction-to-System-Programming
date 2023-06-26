CC=gcc
OBJS=RLEList.o RLEList_example_test.o
EXEC=test
DEBUG=-g
CFLAGS=-std=c99 -Wall -pedantic-errors -Werror $(DEBUG)

$(EXEC): $(OBJS)
	$(CC) $(DEBUG_FLAG) $(OBJS) -o $(EXEC)

RLEList.o: RLEList.c RLEList.h
RLEList_example_test.o: RLEList_example_test.c RLEList.h test_utilities.h

clean:
	rm -f $(OBJS) $(EXEC)