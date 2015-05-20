#include <stdlib.h>
#include <stdbool.h>
#include "array.h"

void bubble_sort (int * data, size_t size){
  int end, i, j;
  bool sorted, swapped;
  sorted = false;
  end = size - 1;
  while(!sorted) {
    sorted = true;
    for(i = 0; i < end; i++){
      j = i + 1;
      if(data[i] > data[j]){
        swap(data, i, j);
        sorted = false;
      }
    }
    end = end - 1;
  }
}
