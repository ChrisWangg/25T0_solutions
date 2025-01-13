# -----------------------------------------------------------------------------
# Compiler settings
# -----------------------------------------------------------------------------
CC = gcc
CFLAGS = -Wall -Werror -std=c11

# -----------------------------------------------------------------------------
# Executable names and object file definitions
# -----------------------------------------------------------------------------
EXEC = setProblems            # For your setProblems
OBJFILES = setProblems.o Set.o

# -----------------------------------------------------------------------------
# The 'all' target will build everything: setProblems, palindrome, 
# testQueue, testBst and twoSum
# -----------------------------------------------------------------------------
all: $(EXEC) palindrome testQueue testBst twoSum

# -----------------------------------------------------------------------------
# Build setProblems
# -----------------------------------------------------------------------------
$(EXEC): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJFILES)

setProblems.o: setProblems.c Set.h
	$(CC) $(CFLAGS) -c setProblems.c

Set.o: Set.c Set.h
	$(CC) $(CFLAGS) -c Set.c

# -----------------------------------------------------------------------------
# Build palindrome
# -----------------------------------------------------------------------------
palindrome: palindrome.c
	$(CC) $(CFLAGS) -o palindrome palindrome.c

# -----------------------------------------------------------------------------
# Build twoSum
# -----------------------------------------------------------------------------
twoSum: twoSum.c
	$(CC) $(CFLAGS) -o twoSum twoSum.c

# -----------------------------------------------------------------------------
# Build testQueue
# -----------------------------------------------------------------------------
testQueue: testQueue.o Queue.o Stack.o
	$(CC) $(CFLAGS) -o testQueue testQueue.o Queue.o Stack.o

testQueue.o: testQueue.c Queue.h
	$(CC) $(CFLAGS) -c testQueue.c

Queue.o: Queue.c Queue.h Stack.h
	$(CC) $(CFLAGS) -c Queue.c

Stack.o: Stack.c Stack.h
	$(CC) $(CFLAGS) -c Stack.c

# -----------------------------------------------------------------------------
# Build testBst
# -----------------------------------------------------------------------------
testBst: testBst.o bst.o
	$(CC) $(CFLAGS) -o testBst testBst.o bst.o

testBst.o: testBst.c bst.h
	$(CC) $(CFLAGS) -c testBst.c

bst.o: bst.c bst.h
	$(CC) $(CFLAGS) -c bst.c

# -----------------------------------------------------------------------------
# Clean up
# -----------------------------------------------------------------------------
clean:
	rm -f *.o $(EXEC) palindrome testQueue testBst