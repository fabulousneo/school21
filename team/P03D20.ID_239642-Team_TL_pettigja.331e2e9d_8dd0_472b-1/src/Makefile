CC = gcc
BUILD = ../build
TARGET = $(BUILD)/graph
SRC = stack.c rpn.c graph.c
CFLAGS = -Wall -Wextra -Werror -std=c11

all: clang cppcheck $(TARGET)

$(TARGET): $(SRC) | $(BUILD)
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) -lm

clang:
	clang-format -i *.c
	clang-format -i *.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c

clean:
	rm -f $(BUILD)/*

rebuild: clean all
