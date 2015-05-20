#include <stdlib.h>
#include "array.h"

void selection_sort (int * data, size_t size){
  int i, j, min_index, last_min;
  for(i = 0; i < size; i++){
    min_index = i;
    for(j = i + 1; j < size; j++){
      if(data[j] < data[min_index]){
        min_index = j;
      }
    }
    if(min_index != i){
      swap(data, i, min_index);
    }
  }
}

