#include <stdlib.h>

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#define INITIAL_LOGICAL_SIZE 0

struct DynamicArray {
  int *data;
  size_t logicalSize;
  double scaleFactor;
};

size_t capacity(const struct DynamicArray *array);
void cleanUp(struct DynamicArray *array);
void grow(struct DynamicArray *array);

void initialise(struct DynamicArray *array, const size_t initialCapacity,
    const double scaleFactor);

void insert(struct DynamicArray *array, const int value);
size_t largerCapacity(const struct DynamicArray *array);
void print(struct DynamicArray *array);
#endif
