#ifndef STATIC_QUEUE_H_
#define STATIC_QUEUE_H_

template <class T>
class StaticQueue {
 public:
  StaticQueue(int queueSize);
  ~StaticQueue();
  void enqueue(T value);
  void dequeue(T &value);
  bool isEmpty();
  bool isFull();
  void clear();

  // Queue Exceptions
  class Overflow {};
  class Underflow {};

 private:
  T* queueArray;
  int queueSize;
  int front;
  int rear;
  int numItems;
};

// Constructor
template <class T>
StaticQueue<T>::StaticQueue(int queueSize) {
  queueArray = new T[queueSize];
  this->queueSize = queueSize;
  front = -1;
  rear = -1;
  numItems = 0;
}

// Destructor
template <class T>
StaticQueue<T>::~StaticQueue() {
  if (numItems > 0)
    delete queueArray;
}

// Enqueue
template <class T>
void StaticQueue<T>::enqueue(T value) {
  if (isFull()) {
    throw Overflow();
  } else {
    rear = (rear + 1) % queueSize;
    queueArray[rear] = value;
    numItems++;
  }
}

// Dequeue
template <class T>
void StaticQueue<T>::dequeue(T &value) {
  if (isEmpty()) {
    throw Underflow();
  } else {
    front = (front + 1) % queueSize;
    value = queueArray[front];
    numItems--;
  }
}

// Clear
template <class T>
void StaticQueue<T>::clear() {
  front = -1;
  rear = -1;
  numItems = 0;
}

// Check if queue is empty
template <class T>
bool StaticQueue<T>::isEmpty() {
  if (numItems > 0)
    return false;
  else 
    return true;
}

// Check is queue is full
template <class T>
bool StaticQueue<T>::isFull() {
  if (numItems < queueSize)
    return false;
  else
    return true;
  
}

#endif