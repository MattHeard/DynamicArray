#include <stdlib.h>

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#define CAPACITY_INDEX 0
#define LOGICAL_SIZE_INDEX 1

#define CAPACITY_FIELD_WIDTH 1
#define LOGICAL_SIZE_FIELD_WIDTH 1
#define METADATA_WIDTH CAPACITY_FIELD_WIDTH + LOGICAL_SIZE_FIELD_WIDTH

#define INITIAL_LOGICAL_SIZE 0

struct DynamicArray {
  int *data;
  double scaleFactor;
};

size_t capacity(const struct DynamicArray *array);
void cleanUp(struct DynamicArray *array);
void grow(struct DynamicArray *array);

void initialise(struct DynamicArray *array, const size_t initialCapacity,
    const double scaleFactor);

void insert(struct DynamicArray *array, const int value);
size_t largerCapacity(const struct DynamicArray *array);
size_t logicalSize(const struct DynamicArray *array);
void print(struct DynamicArray *array);
#endif
