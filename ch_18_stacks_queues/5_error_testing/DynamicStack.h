#ifndef DYNAMIC_STACK_H_
#define DYNAMIC_STACK_H_

#include <new>

template <class T>
class DynamicStack {
 public:
  DynamicStack() { top == nullptr; }
  void push(T value);
  void pop(T &value);
  bool isEmpty();

  // Stack Exceptions
  class Underflow {};
  class PushMemError {};

 private:
  class StackNode {
    friend class DynamicStack;
    T value;
    StackNode* next;

    // Node Constructor
    StackNode(T newValue, StackNode* newNext = nullptr) {
      value = newValue;
      next = newNext;
    }
  };
  StackNode* top;
};

template <class T>
void DynamicStack<T>::push(T value) {
  try {
    top = new StackNode(value top);
  } catch (bad_alloc) {
    throw PushMemError();
  }
}

template <class T>
bool DynamicStack<T>::isEmpty() {
  if (!top)
    return true;
  else
    return false;  
}

template <class T>
void DynamicStack<T>::pop(T &value) {
  if (isEmpty()) {
    throw Underflow();
  } else {
    StackNode* garbage;
    value = top->value;
    garbage = top;
    top = top->next;
    delete garbage;
  }
}

#endif