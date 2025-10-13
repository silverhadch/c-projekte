CC = gcc

# Aggressive warnings, debug info, sanitizers, and pedantic mode
CFLAGS = -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion \
         -Wformat=2 -Wnull-dereference -Wdouble-promotion -Wimplicit-fallthrough \
         -Wundef -fanalyzer -fsanitize=undefined,address -g3 -O0

LDFLAGS = -lncurses -fsanitize=undefined,address

TARGET = main
SRC = main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

