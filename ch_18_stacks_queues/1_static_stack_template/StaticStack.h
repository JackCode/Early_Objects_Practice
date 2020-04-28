#ifndef STATIC_STACK_H_
#define STATIC_STACK_H_

template <class T>
class StaticStack {
 public:
  StaticStack<T>(int capacity);
  ~StaticStack() { if( top!= 0) delete stackArray; }
  void push(T value);
  void pop (T &value);
  bool isEmpty();

  // Stack Exceptions
  class Overflow {};
  class Underflow {};

 private:
  T* stackArray;
  int capacity;
  int top;
};

// Constructor
template <class T>
StaticStack<T>::StaticStack(int capacity) {
  this->capacity = capacity;
  stackArray = new T[capacity];
  top = 0;
}

// Add value to stack
template <class T>
void StaticStack<T>::push(T value) {
  if (top == capacity) {
    throw StaticStack::Overflow();
  } else {
    stackArray[top] = value;
    top++;
  }
}

// Check if empty
template <class T>
bool StaticStack<T>::isEmpty() {
  if (top == 0)
    return true;
  else
    return false;
  
}

// Remove value from stack and return it
template <class T>
void StaticStack<T>::pop(T &value) {
  if (isEmpty()) {
    throw StaticStack::Underflow();
  } else {
    top--;
    value = stackArray[top];
  }
}


#endif