#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

void cleanUp(struct DynamicArray *array) {
  free(array->elements);
}

void grow(struct DynamicArray *array) {
  const size_t newCapacity = largerCapacity(array);
  printf("capacity changing from %zu to %zu\n", array->capacity, newCapacity);
  int *largerBuffer = realloc(array->elements, newCapacity * sizeof(int));
  if (largerBuffer == NULL) {
    abort();
  }
  array->elements = largerBuffer;
  array->capacity = newCapacity;
}

void initialise(struct DynamicArray *array, const size_t initialCapacity,
    const double scaleFactor) {
  const size_t size = initialCapacity * sizeof(int);
  array->elements = malloc(size);
  if (array->elements == NULL) {
    abort();
  }
  array->capacity = initialCapacity;
  array->logicalSize = INITIAL_LOGICAL_SIZE;
  array->scaleFactor = scaleFactor;
}

void insert(struct DynamicArray *array, const int value) {
  if (array->capacity == array->logicalSize) {
    grow(array);
  }
  array->elements[array->logicalSize] = value;
  (array->logicalSize)++;
}

const size_t largerCapacity(const struct DynamicArray *array) {
  return array->capacity * array->scaleFactor;
}

void print(struct DynamicArray *array) {
  printf("[ ");
  for (size_t i = 0; i < array->logicalSize; i++) {
    printf("%d ", array->elements[i]);
  }
  printf("]\n");
}
