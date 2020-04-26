#include <iostream>

#include "LinkedList.h"

int main() {
  LinkedList list;
  list.add(3);
  list.add(6.760);
  list.add(9);
  list.add(1.5);

  std::cout << list.isMember(1.5) << "\n";

  return 0;
}