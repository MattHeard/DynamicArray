#include "dynamic_array.h"

int main() {
  struct DynamicArray array;
  initialise(&array);
  print(&array);
  for (size_t i = 0; i < 4; i++) {
    insert(&array, i);
    print(&array);
  }
  cleanUp(&array);
  return EXIT_SUCCESS;
}
