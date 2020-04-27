#include "LinkedList.h"

// Default Constructor
LinkedList::LinkedList() {
  head = nullptr;
}

// Copy Constructor
LinkedList::LinkedList(const LinkedList& obj) {
  ListNode* ptr = head;
  this->head = obj.head;

  while (ptr != nullptr) {
    ListNode* garbage = ptr;
    ptr = ptr->next;
    delete garbage;
  }
}

// Destructor
LinkedList::~LinkedList() {
  ListNode* ptr = head;

  while (ptr != nullptr) {
    ListNode* garbage = ptr;
    ptr = ptr->next;
    delete garbage;
  }
}

// Add new node
void LinkedList::add(double x) {
  head = new ListNode(x, head);
}

// Search through list for value
bool LinkedList::isMember(double x) {
  ListNode *ptr = head;

  while(ptr != nullptr) {
    if (ptr->entry == x)
      return true;
    ptr = ptr->next;
  }
  return false;
}