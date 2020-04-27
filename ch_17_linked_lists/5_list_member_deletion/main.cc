#include <iostream>

#include "LinkedList.h"

int main() {
  LinkedList list;
  int numberSearch = 5;

  std::cout << "List contents: "; list.print();

  for (int i = 0; i < 10; i+=2)
    list.add(i+3);

  std::cout << "List contents: "; list.print();

  if (list.isMember(list.getFirstNode(), numberSearch))
    std::cout << numberSearch << " is in the list\n";
  else
    std::cout << numberSearch << " is not in the list\n";
  
    std::cout << "List contents: "; list.print();
  list.remove(numberSearch);

  if (list.isMember(list.getFirstNode(), numberSearch))
    std::cout << numberSearch << " is in the list\n";
  else
    std::cout << numberSearch << " is not in the list\n";

  std::cout << "List contents: "; list.print();

  return 0;
}