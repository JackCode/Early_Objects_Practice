#include "LinkedList.h"

// Constructor
LinkedList::LinkedList() {
  head = nullptr;
}

// Destructor
LinkedList::~LinkedList() {
  ListNode* ptr = head;

  while (ptr != nullptr) {
    ListNode* garbage;
    garbage = ptr;
    ptr = ptr->next;
    delete garbage;
  }
}

// Add new node
void LinkedList::add(double x) {
  head = new ListNode(x, head);
}

// Search list for value
bool LinkedList::isMember(double x) {
  ListNode *ptr = head;

  while(ptr != nullptr) {
    if (ptr->entry == x)
      return true;
    ptr = ptr->next;
  }
  return false;
}