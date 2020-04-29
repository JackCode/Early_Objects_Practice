#ifndef BIN_STACK_H_
#define BIN_STACK_H_

#include "Item.h"
#include "Date.h"

namespace jw {

class BinStack {
 public:
  BinStack() { this->topItem = nullptr; }
  ~BinStack();
  
  void push(Item &newItem);
  void pop();
  jw::Item top();
  bool empty();
  void displayStack();

  // Exception Classes
  class PushMemError {};
  class InvalidAccess {};

 private:
  class ItemNode {
    friend class BinStack;
    jw::Item item;
    ItemNode* next;

    ItemNode(jw::Item newItem, ItemNode* newNext) {
      item = newItem;
      next = newNext;
    }
  };
  ItemNode* topItem;
};

}

#endif