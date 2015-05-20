#ifndef ARRAY_H_
#define ARRAY_H_

void swap_addr (int** a, int** b);
void swap (int * arr, int index1, int index2);
void insert(int * arr, int val, int index, size_t size);
void copy ( int * src, int * dst, size_t size);
void move (int * data, int index_from, int index_to);
void print_range (int * arr, int start_index, int end_index);
void print_arr (int * arr, size_t size);

#endif
