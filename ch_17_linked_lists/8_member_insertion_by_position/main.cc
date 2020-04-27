#include <iostream>

#include "LinkedList.h"

int main() {
  LinkedList list;

  for (int i = 0; i < 10; i++)
    list.add(i);

  list.print();

  list.insert(3.14, 4);
  list.print();

  list.insert(99, 0);
  list.print();

  list.insert(105.77, 15);
  list.print();

  return 0;
}