#include <iostream>
#include <new>

#include "BinStack.h"
#include "Item.h"
#include "Date.h"

// Destructor
jw::BinStack::~BinStack() {
  system("clear");
  std::cout << "Remaining Inventory\n\n";
  if(empty())
    std::cout << "No parts remaining in inventory.\n\n";
  else 
    displayStack();
  
  while (!empty()) {
    pop();
  }
}

// Push new item on stack
void jw::BinStack::push(Item &newItem) {
  try {
    topItem = new ItemNode(newItem, topItem);
  } catch (std::bad_alloc) {
    throw BinStack::PushMemError();
  }
}

// Pops item from top of list -- Does not return item
void jw::BinStack::pop() {
  if (!empty()) {
    ItemNode* garbage = topItem;
    topItem = topItem->next;
    delete garbage;
  }
}

// Return Item on top of stack -- Does not remove from stack
jw::Item jw::BinStack::top() {
  if (!empty()) {
    return topItem->item;
  } else {
    throw InvalidAccess();
  }
}

// Checks if stack is empty
bool jw::BinStack::empty() {
  if (topItem == nullptr)
    return true;
  else
    return false;
}

// Displays contents of Bin Stack
void jw::BinStack::displayStack() {
  ItemNode* ptr = topItem;

  while (ptr != nullptr) {
    std::cout << "Serial #: " << ptr->item.getSerialNumber() << "\n";
    std::cout << "Lot #: " << ptr->item.getLotNumber() << "\n";
    std::cout << "Manufacture Date: " << ptr->item.getDate() << "\n";
    std::cout << "\n";
    ptr = ptr->next;
  }
}