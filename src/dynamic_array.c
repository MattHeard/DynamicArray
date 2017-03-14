#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

#define CAPACITY_INDEX 0
#define CAPACITY_FIELD_WIDTH 1

size_t capacity(const struct DynamicArray *array) {
  return array->data[CAPACITY_INDEX];
}

void cleanUp(struct DynamicArray *array) {
  free(array->data);
}

void grow(struct DynamicArray *array) {
  const size_t newCapacity = largerCapacity(array);
  printf("capacity changing from %zu to %zu\n", capacity(array), newCapacity);
  const size_t largerBufferWidth = CAPACITY_FIELD_WIDTH + newCapacity;
  int *largerBuffer = realloc(array->data, largerBufferWidth * sizeof(int));
  if (largerBuffer == NULL) {
    abort();
  }
  array->data = largerBuffer;
  array->data[CAPACITY_INDEX] = newCapacity;
}

void initialise(struct DynamicArray *array, const size_t initialCapacity,
    const double scaleFactor) {
  const size_t bufferWidth = CAPACITY_FIELD_WIDTH + initialCapacity;
  array->data = malloc(bufferWidth * sizeof(int));
  if (array->data == NULL) {
    abort();
  }
  array->data[CAPACITY_INDEX] = initialCapacity;
  array->logicalSize = INITIAL_LOGICAL_SIZE;
  array->scaleFactor = scaleFactor;
}

void insert(struct DynamicArray *array, const int value) {
  if (capacity(array) == array->logicalSize) {
    grow(array);
  }
  const size_t elementIndex = CAPACITY_FIELD_WIDTH + array->logicalSize;
  array->data[elementIndex] = value;
  (array->logicalSize)++;
}

size_t largerCapacity(const struct DynamicArray *array) {
  return capacity(array) * array->scaleFactor;
}

void print(struct DynamicArray *array) {
  printf("[ ");
  for (size_t i = 0; i < array->logicalSize; i++) {
    const size_t elementIndex = CAPACITY_FIELD_WIDTH + i;
    printf("%d ", array->data[elementIndex]);
  }
  printf("]\n");
}
