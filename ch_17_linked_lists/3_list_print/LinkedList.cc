#include <iostream>

#include "LinkedList.h"

// Constructors
LinkedList::LinkedList() {
  head = nullptr;
}

// Copy Constructor
LinkedList::LinkedList(const LinkedList& obj) {
  ListNode* destruct = head;
  this->head = obj.head;

  // Clean up old list memory
  while (destruct != nullptr) {
    ListNode* garbage = destruct;
    destruct = destruct->next;
    delete garbage;
  }
}

// Destructor
LinkedList::~LinkedList() {
  ListNode *ptr = head;

  while (ptr != nullptr) {
    ListNode* garbage = ptr;
    ptr = ptr->next;
    delete garbage;
  }
}

// Member functions
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

void LinkedList::print() {
  ListNode *ptr = head;

  while (ptr != nullptr) {
    std::cout << ptr->entry << " ";
    ptr = ptr->next;
  }
  std::cout << "\n";
}