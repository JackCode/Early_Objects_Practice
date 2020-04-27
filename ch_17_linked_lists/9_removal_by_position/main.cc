#include <iostream>

#include "LinkedList.h"

int main() {
  LinkedList list;

  for (int i = 0; i < 10; i++)
    list.add(i);

  list.print();

  list.add(3.14, 4);
  list.print();

  list.removeVal(3.14);
  list.print();
  list.removePos(7);
  list.print();

  list.removePos(20);
  list.print();


  return 0;
}