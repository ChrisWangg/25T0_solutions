# --------------------------------------------------
#  Makefile for testReachable
# --------------------------------------------------
CC     = gcc
CFLAGS = -Wall -Werror -g

.PHONY: all clean

# The default goal; builds the executable
all: reachable

# Link objects into final executable
reachable: reachable.o Graph.o Set.o
	$(CC) $(CFLAGS) -o reachable reachable.o Graph.o Set.o

# Compile reachable.c into an object
reachable.o: reachable.c Graph.h Set.h
	$(CC) $(CFLAGS) -c reachable.c

# Compile Graph.c
Graph.o: Graph.c Graph.h
	$(CC) $(CFLAGS) -c Graph.c

# Compile Set.c
Set.o: Set.c Set.h
	$(CC) $(CFLAGS) -c Set.c

# Clean up any build artifacts
clean:
	rm -f *.o reachable
