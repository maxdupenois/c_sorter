#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "array.h"
#include "algorithms.h"

#define MAX_DATA 100
#define MAX_DATUM_LENGTH 100

void print_algorithm_choices();

int main() {
  //int arr[] = { 3, 1, 7, 10, 0, -1 };
  //size_t size = sizeof(arr) / sizeof(arr[0]);
  int algorithm, index  = 0;
  size_t data_size;
  int data[MAX_DATA];
  char line[MAX_DATUM_LENGTH];
  char c;

  printf("Enter data, a blank line finishes:\n");
  do {
    for(index = 0; (c = getchar()) != '\n'; index++){
      line[index] = c;
    }
    line[index] = '\0';
    if(line[0] != '\0'){
      data[data_size] = atoi(line);
      data_size++;
    }
  } while(line[0] != '\0');

  print_algorithm_choices();
  scanf("%i", &algorithm);

  switch(algorithm) {
    case 1:
      bubble_sort(data, data_size);
      break;
    case 2:
      merge_sort(data, data_size);
      break;
    case 3:
      insertion_sort(data, data_size);
      break;
    case 4:
      selection_sort(data, data_size);
      break;
    default:
      printf("Unrecognised algorithm choice\n");
      return 1;
  }
  print_arr(data, data_size);
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
