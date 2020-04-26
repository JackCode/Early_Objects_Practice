#include "LinkedList.h"

// Constructors
LinkedList::LinkedList() {
  head = nullptr;
}

// Copy Constructor
LinkedList::LinkedList(const LinkedList& obj) {
  this->head = obj.head;
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