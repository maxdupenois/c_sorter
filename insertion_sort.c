#include <stdlib.h>
#include <stdbool.h>
#include "array.h"

void insertion_sort (int * data, size_t size){
  int i, j, sorted_head;
  bool found_insert;
  sorted_head = 0;
  for(i = 1; i < size; i++){
    found_insert = false;
    for(j = sorted_head; j >= 0 && !found_insert; j--){
      if(data[i] >= data[j]){
        move(data, i, j + 1);
        found_insert = true;
      }
    }
    if (!found_insert){
      move(data, i, 0);
    }
    sorted_head++;
  }
}
