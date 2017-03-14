#include "dynamic_array.h"

int main() {
  struct DynamicArray array;
  initialise(&array);
  print(&array);
  const size_t numIterations = 17;
  for (size_t i = 0; i < numIterations; i++) {
    insert(&array, i);
    print(&array);
  }
  cleanUp(&array);
  return EXIT_SUCCESS;
}
