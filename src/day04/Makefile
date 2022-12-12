CC = gcc
CFLAGS = -Wall -std=gnu99 -Werror -g
TARGET = main
OBJECTS = main.o

all: $(TARGET)

main: main.c
	$(CC) $(CFLAGS) -o main main.c

run: main.c
	./main

clean:
	rm -f $(TARGET) $(OBJECTS) *~ *.o *.out *.exe *.stackdump *.dSYM