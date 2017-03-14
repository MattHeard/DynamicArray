#include "dynamic_array.h"

int main() {
  struct DynamicArray array;
  const size_t initialCapacity = 2;
  const double scaleFactor = 3.5;
  initialise(&array, initialCapacity, scaleFactor);
  print(&array);
  const size_t numIterations = 17;
  for (size_t i = 0; i < numIterations; i++) {
    insert(&array, i);
    print(&array);
  }
  cleanUp(&array);
  return EXIT_SUCCESS;
}
