#include <iostream>

#include "LinkedList.h"

int main() {
  LinkedList list;

  list.reverse();
  list.add(5);
  list.print();
  list.reverse();
  list.print();

  list.add(4);
  list.add(3);
  list.add(2);
  list.add(1);

  list.print();
  list.reverse();
  list.print();

  list.remove(2);
  list.print();
  list.reverse();
  list.print();

  return 0;
}