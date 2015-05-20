# Makefile
#LDFLAGS=-lncurses
#all: game
CC=gcc
CFLAGS=-I.
DEPS=array.h algorithms.h
OBJ=sort.o array.o bubble_sort.o insertion_sort.o merge_sort.o selection_sort.o

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

sorter: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
