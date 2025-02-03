# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Source files
SRCS = threeSum.c HashTable.c

# Object files
OBJS = $(SRCS:.c=.o)

# Name of the executable
TARGET = threeSum

# Default rule: build the executable
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
