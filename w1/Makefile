# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Source files
SRC1 = listCode.c

# Output executables
OUT1 = listCode

# Default target
all: $(OUT1)

# Rule to compile listCode.c into an executable
$(OUT1): $(SRC1)
	$(CC) $(CFLAGS) -o $(OUT1) $(SRC1)

# Clean target to remove the executables
clean:
	rm -f $(OUT1)

# PHONY targets
.PHONY: all clean
