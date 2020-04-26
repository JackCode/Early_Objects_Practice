#include <iostream>
#include "LinkedList.h"

int main() {
  LinkedList list1;
  LinkedList list2;

  list1.add(1);
  list1.add(2);
  list1.add(3);
  list1.add(4);

  list2.add(5);
  list2.add(6);

  std::cout << list1.isMember(5) << "\n";
  list1 = list2;

  std::cout << list1.isMember(5) << "\n";

  return 0;
}