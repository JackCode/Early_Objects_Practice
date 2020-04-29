#include "StringQueue.h"

#include <new>

// Constructor
StringQueue::StringQueue() {
  front = nullptr;
  rear = nullptr;
}

// Copy Constructor
StringQueue::StringQueue(const StringQueue& obj) {
  if (obj.front != nullptr) {
    LetterNode* ptr;
    this->front = new LetterNode(obj.front->value);
    this->rear = this->front;
    ptr = obj.front->next;

    while (ptr != nullptr) {
      this->enqueue(ptr->value);
      ptr = ptr->next;
    }
  }
}

// Assignment = operator overload
void StringQueue::operator=(const char* str) {
  clear(); // Clear out current contents

  int charCount = 0;
  front = nullptr;
  rear = nullptr;

  do {
    enqueue(*(str+charCount));
    charCount++;
  } while (*(str+charCount) != '\0');
}

// Assignment = operator overload
void StringQueue::operator=(const StringQueue& obj) {
  clear(); // Clear out current contents
  if (obj.front != nullptr) {
    LetterNode* ptr;
    this->front = new LetterNode(obj.front->value);
    this->rear = this->front;
    ptr = obj.front->next;

    while (ptr != nullptr) {
      this->enqueue(ptr->value);
      ptr = ptr->next;
    }
  }
}

// Destructor
StringQueue::~StringQueue() {
  clear();
}

// Enqueue
void StringQueue::enqueue(char letter) {
  if (isEmpty()) {
    try {
      front = new LetterNode(letter);
      rear = front;
    } catch (std::bad_alloc) {
      throw StringQueue::EnqueueMemErr();
    }
  } else {
    try {
      rear->next = new LetterNode(letter);
      rear = rear->next;
    } catch (std::bad_alloc) {
      throw StringQueue::EnqueueMemErr();
    }
  }
}

// Dequeue
void StringQueue::dequeue(char &letter) {
  if (isEmpty()) {
    throw StringQueue::Underflow();
  } else {
    LetterNode* garbage;
    letter = front->value;
    garbage = front;
    front = front->next;
    delete garbage;
  }
}

// Check if empty
bool StringQueue::isEmpty() {
  if (front == nullptr)
    return true;
  else 
    return false;
}

// Clear string queue
void StringQueue::clear() {
  char temp;

  while (!isEmpty())
    dequeue(temp);
}

// Return length of StringQueue
int StringQueue::length() {
  LetterNode* ptr = front;
  int letterCount = 0;

  while (ptr != nullptr) {
    letterCount++;
    ptr = ptr->next;
  }
  return letterCount;
}

// [ ] Operator Overload
char StringQueue::operator[](int index) {
  LetterNode* ptr = front;
  int currentIndex = 0;

  while (ptr != nullptr) {
    if (currentIndex == index) {
      return ptr->value;
    }
    ptr = ptr->next;
    currentIndex++;
  }
  return '\0';
}

// << Overload Operator
std::ostream& operator<<(std::ostream& out, const StringQueue& str) {
  StringQueue temp = str;
  char letter;

  while (!temp.isEmpty()) {
    temp.dequeue(letter);
    out << letter;
  }
  return out;
}