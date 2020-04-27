#include <iostream>

#include "LinkedList.h"

int main() {
  LinkedList list;
  const double searchValue = 4;

  for (int i = 9; i >= 0; i--)
    list.add(static_cast<double>(i));
  
  list.print();

  int foundPos = list.search(searchValue);

  if (foundPos != -1) {
    std::cout << searchValue << " was found in position " << foundPos << "\n";
  } else {
    std::cout << searchValue << " was not found.\n";
  }

  return 0;
}