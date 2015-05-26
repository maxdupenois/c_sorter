#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "array.h"
#include "algorithms.h"

#define MAX_DATA 100
#define MAX_DATUM_LENGTH 100

struct data_struct {
  int * data_arr;
  size_t size;
};

void print_algorithm_choices();
void collect_data(struct data_struct * data);

int main() {
  int algorithm = 0;
  struct data_struct data;
  data.data_arr = calloc(MAX_DATA, sizeof(int));
  data.size = 0;

  collect_data(&data);
  printf("Unsorted:\n-------\n");
  print_arr(data.data_arr, data.size);
  printf("\n");

  print_algorithm_choices();
  scanf("%i", &algorithm);

  switch(algorithm) {
    case 1:
      bubble_sort(data.data_arr, data.size);
      break;
    case 2:
      merge_sort(data.data_arr, data.size);
      break;
    case 3:
      insertion_sort(data.data_arr, data.size);
      break;
    case 4:
      selection_sort(data.data_arr, data.size);
      break;
    default:
      printf("Unrecognised algorithm choice\n");
      return 1;
  }
  printf("\nSorted:\n-------\n");
  print_arr(data.data_arr, data.size);
  free(data.data_arr);
  return 0;
}

void print_algorithm_choices(){
  printf("Select Algorithm to Use:\n");
  printf("-----------------------:\n");
  printf("1. Bubble Sort.\n");
  printf("2. Merge Sort.\n");
  printf("3. Insertion Sort.\n");
  printf("4. Selection Sort.\n");
}

void collect_data(struct data_struct * data){
  int index = 0;
  char c;
  char line[MAX_DATUM_LENGTH];

  printf("Enter data, a blank line finishes:\n");
  do {
    for(index = 0; (c = getchar()) != '\n'; index++){
      line[index] = c;
    }
    line[index] = '\0';
    if(line[0] != '\0'){
      data->data_arr[data->size] = atoi(line);
      data->size++;
    }
  } while(line[0] != '\0');
}
