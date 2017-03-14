#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

size_t capacity(const struct DynamicArray *array) {
  return array->data[CAPACITY_INDEX];
}

void cleanUp(struct DynamicArray *array) {
  free(array->data);
}

void grow(struct DynamicArray *array) {
  const size_t newCapacity = largerCapacity(array);
  printf("capacity changing from %zu to %zu\n", capacity(array), newCapacity);
  const size_t largerBufferWidth = METADATA_WIDTH + newCapacity;
  int *largerBuffer = realloc(array->data, largerBufferWidth * sizeof(int));
  if (largerBuffer == NULL) {
    abort();
  }
  array->data = largerBuffer;
  array->data[CAPACITY_INDEX] = newCapacity;
}

void initialise(struct DynamicArray *array, const size_t initialCapacity,
    const double scaleFactor) {
  const size_t bufferWidth = METADATA_WIDTH + initialCapacity;
  array->data = malloc(bufferWidth * sizeof(int));
  if (array->data == NULL) {
    abort();
  }
  array->data[CAPACITY_INDEX] = initialCapacity;
  array->data[LOGICAL_SIZE_INDEX] = INITIAL_LOGICAL_SIZE;
  array->scaleFactor = scaleFactor;
}

void insert(struct DynamicArray *array, const int value) {
  if (capacity(array) == logicalSize(array)) {
    grow(array);
  }
  const size_t elementIndex = METADATA_WIDTH + logicalSize(array);
  array->data[elementIndex] = value;
  (array->data[LOGICAL_SIZE_INDEX])++;
}

size_t largerCapacity(const struct DynamicArray *array) {
  return capacity(array) * array->scaleFactor;
}

size_t logicalSize(const struct DynamicArray *array) {
  return array->data[LOGICAL_SIZE_INDEX];
}

void print(struct DynamicArray *array) {
  printf("[ ");
  for (size_t i = 0; i < logicalSize(array); i++) {
    const size_t elementIndex = METADATA_WIDTH + i;
    printf("%d ", array->data[elementIndex]);
  }
  printf("]\n");
}
