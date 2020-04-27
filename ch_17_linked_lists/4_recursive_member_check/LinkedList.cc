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

// Add new node
void LinkedList::add(double x) {
  head = new ListNode(x, head);
}

// Recursively search through list for value
bool LinkedList::isMember(ListNode* obj, double x) {
  if (obj->next == nullptr)
    return false;
  else
    return obj->entry == x || isMember(obj->next, x);  
}

// Print all values in list
void LinkedList::print() {
  ListNode *ptr = head;

  while (ptr != nullptr) {
    std::cout << ptr->entry << " ";
    ptr = ptr->next;
  }
  std::cout << "\n";
}