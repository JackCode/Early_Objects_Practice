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
void LinkedList::add(double value) {
  head = new ListNode(value, head);
}

// Removes first occurrence of value
void LinkedList::remove(double value) {
  ListNode* firstNode = head;

  if (firstNode->entry == value) {
    head = firstNode->next;
    delete firstNode;
    return;
  }

  ListNode* prevNode;

  while (firstNode != nullptr) {
    prevNode = firstNode;
    firstNode = firstNode->next;

    if (firstNode->entry == value) {
      prevNode->next = firstNode->next;
      delete firstNode;
      return;
    }
  }
}

// Recursively search through list for value
bool LinkedList::isMember(ListNode* obj, double value) {
  if (obj->next == nullptr)
    return false;
  else
    return obj->entry == value || isMember(obj->next, value);  
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