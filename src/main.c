#include "dynamic_array.h"

int main() {
  struct DynamicArray array;
  initialise(&array);
  print(&array);
  insert(&array, 1);
  print(&array);
  insert(&array, 2);
  print(&array);
  insert(&array, 3);
  print(&array);
  insert(&array, 4);
  print(&array);
  cleanUp(&array);
  return 0;
}
