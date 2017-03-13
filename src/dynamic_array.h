#include <stdlib.h>

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#define INITIAL_CAPACITY 2
#define INITIAL_LOGICAL_SIZE 0
#define SCALE_FACTOR 2

struct DynamicArray {
  int *elements;
  int capacity;
  int logicalSize;
};

void cleanUp(struct DynamicArray *array);
void grow(struct DynamicArray *array);
void initialise(struct DynamicArray *array);
void insert(struct DynamicArray *array, const int value);
void print(struct DynamicArray *array);
#endif
