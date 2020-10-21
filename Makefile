CC=g++
CFLAGS=-c -Wall

all: fibonacci

fibonacci: main_fibonacci.o fibonacci_word.o
    $(CC) $(CFLAGS) main_fibonacci.o fibonacci_word.o -o fibonacci

main_fibonacci.o: main_fibonacci.cc fibonacci_word.o
    $(CC) $(CFLAGS) main_fibonacci.cc

fibonacci_word.o: fibonacci_word.cc
    $(CC) $(CFLAGS) fibonacci_word.cc

.PHONY: clean

clean:
    rm -f *o fibonacci