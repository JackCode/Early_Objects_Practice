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

// Reverse order of list
void LinkedList::reverse() {
  // If list is empty or has one node, do nothing
  if (head == nullptr || head->next == nullptr)
    return;

  // If list has two or more nodes
  ListNode* second = head;
  ListNode* first = second->next; 
  ListNode* third = nullptr;

  while (first != nullptr) {
   second->next = third;
   third = second;
   second = first;
   first = first->next; 
  }
  second->next = third;
  head = second;
}

// Search list for value and return position of first occurrence
int LinkedList::search(double value) {
  ListNode* ptr = head;
  int index = 0;

  // If list is empty, return -1
  if (ptr == nullptr)
    return -1;

  // Return index if value is found
  while (ptr != nullptr) {
    if (ptr->entry == value)
      return index;
    ptr = ptr->next;
    index++;
  }

  // Return -1 if value isn't found
  return -1;
}

// Insert value into given position
void LinkedList::insert(double value, int pos) {
  // Base case: insert at front of list
  if (pos <= 0) {
    add(value);
    return;
  }  

  ListNode* second = head; 
  ListNode* first = second->next;
  int index = 1;

  // Traverse list until position is found or end of list
  while (true) {
    if (index == pos || first == nullptr) {
      second->next = new ListNode(value, first);
      return;
    }
    second = first;
    first = first->next;
    index++;
  }
}