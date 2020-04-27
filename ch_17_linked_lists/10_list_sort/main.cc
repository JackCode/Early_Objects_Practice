#include <iostream>
#include <ctime>
#include "LinkedList.h"

int main() {
  LinkedList list;
  srand(time(0));

  for (int i = 0; i < 10; i++)
    list.add(rand()%365);

  list.print();
  list.sortAsc();
  list.print();

  return 0;
}