#ifndef DYNAMIC_QUEUE_H_
#define DYNAMIC_QUEUE_H_

template <class T>
class DynamicQueue {
 public:
  DynamicQueue();
  ~DynamicQueue();

  void enqueue(T value);
  void dequeue(T &value);
  bool isEmpty();
  void clear();

  class Underflow {};

 private:
  class QueueNode {
    friend class DynamicQueue;
    T value;
    QueueNode* next;

    // Node Constructor
    QueueNode(T newValue, QueueNode* newNext = nullptr) {
      value = newValue;
      next = newNext;
    }
  }; 
  QueueNode* front;
  QueueNode* rear;
};

// Constructor
template <class T>
DynamicQueue<T>::DynamicQueue() {
  front = nullptr;
  rear = nullptr;
}

// Destructor
template <class T>
DynamicQueue<T>::~DynamicQueue() {
  clear();
}

// Enqueue
template <class T>
void DynamicQueue<T>::enqueue(T value) {
  if (isEmpty()) {
    front = new QueueNode(value);
    rear = front;
  } else {
    rear->next = new QueueNode(value);
    rear = rear->next;
  }
}

// Dequeue
template <class T>
void DynamicQueue<T>::dequeue(T &value) {
  if (ifEmpty()) {
    throw Underflow();
  } else {
    QueueNode* garbage;
    value = front->value;
    garbage = front;
    front = front->next;
    delete garbage;
  }
}

// Check is queue is empty
template <class T>
bool DynamicQueue<T>::isEmpty() {
  if (front == nullptr)
    return true;
  else 
    return false;
}

// Clear queue
template <class T>
void DynamicQueue<T>::clear() {
  T value;

  while (!isEmpty)
    dequeue(value);
}

#endif