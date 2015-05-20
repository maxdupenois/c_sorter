#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void swap_addr (int** a, int** b){
  int * temp = *a;
  *a = *b;
  *b = temp;
}
void swap(int * arr, int index1, int index2){
  int tmp;
  tmp = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = tmp;
}

void insert(int * arr, int val, int index, size_t size){
  int i;
  for(i = size - 2; i >= index; i--){
    arr[i+1] = arr[i];
  }
  arr[index] = val;
}

void copy ( int * src, int * dst, size_t size){
  int i;
  for(i = 0; i < size; i++) dst[i] = src[i];
}

void move (int * data, int index_from, int index_to){
  int tmp;
  int i;
  tmp = data[index_from];
  if (index_from < index_to){
    for(i = index_from + 1; i <= index_to; i++){
      data[i - 1] = data[i];
    }
  } else if (index_from > index_to) {
    for(i = index_from - 1; i >= index_to; i--){
      data[i + 1] = data[i];
    }
  }
  data[index_to] = tmp;
}

void print_range (int * arr, int start_index, int end_index){
  int i;
  for(i = start_index; i <= end_index; i++){
    if(i != start_index) printf(", ");
    printf("%d", arr[i]);
  }
  printf("\n");
}

void print_arr (int * arr, size_t size){
  print_range(arr, 0, size - 1);
}
