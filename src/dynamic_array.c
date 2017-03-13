#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

void cleanUp(struct DynamicArray *array) {
  int *elements = array->elements;
  free(elements);
}

void grow(struct DynamicArray *array) {
  const size_t newCapacity = array->capacity * 2;
  void *elements = (void *) array->elements;
  array->elements = (int *) realloc(elements, newCapacity);
  array->capacity = newCapacity;
}

void initialise(struct DynamicArray *array) {
  const size_t size = INITIAL_CAPACITY * sizeof(int);
  array->elements = malloc(size);
  array->capacity = INITIAL_CAPACITY;
  array->logicalSize = 0;
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
    const int element = array->elements[i];
    printf("%d ", element);
  }
  printf("]\n");
}
