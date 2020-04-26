#include "LinkedList.h"

LinkedList::LinkedList() {
  head = nullptr;
}

void LinkedList::add(double x) {
  head = new ListNode(x, head);
}

bool LinkedList::isMember(double x) {
  ListNode *ptr = head;

  while(ptr != nullptr) {
    if (ptr->entry == x)
      return true;
    ptr = ptr->next;
  }
  return false;
}