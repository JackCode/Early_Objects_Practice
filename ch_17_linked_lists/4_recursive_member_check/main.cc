#include <iostream>

#include "LinkedList.h"

int main() {
  LinkedList list;

  list.add(4);
  list.add(7);
  list.add(1);

  std::cout << list.isMember(list.getFirstNode(), 2) << std::endl;
  std::cout << list.isMember(list.getFirstNode(), 1) << std::endl;

  return 0;
}