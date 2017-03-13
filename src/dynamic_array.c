#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

void cleanUp(struct DynamicArray *array) {
  free(array->elements);
}

void grow(struct DynamicArray *array) {
  const size_t newCapacity = array->capacity * SCALE_FACTOR;
  void *elements = (void *) array->elements;
  array->elements = (int *) realloc(elements, newCapacity);
  array->capacity = newCapacity;
}

void initialise(struct DynamicArray *array) {
  const size_t size = INITIAL_CAPACITY * sizeof(int);
  array->elements = malloc(size);
  array->capacity = INITIAL_CAPACITY;
  array->logicalSize = INITIAL_LOGICAL_SIZE;
}

void insert(struct DynamicArray *array, const int value) {
  if (array->capacity == array->logicalSize) {
    grow(array);
  }
  array->elements[array->logicalSize] = value;
  (array->logicalSize)++;
}

void print(struct DynamicArray *array) {
  printf("[ ");
  for (size_t i = 0; i < array->logicalSize; i++) {
    printf("%d ", array->elements[i]);
  }
  printf("]\n");
}
