#ifndef STRING_QUEUE_H_
#define STRING_QUEUE_H_

#include <string>
#include <iostream>

class StringQueue {
 public:
  StringQueue();
  StringQueue(const StringQueue& obj);
  ~StringQueue();

  void enqueue(char letter);
  void dequeue(char &letter);
  bool isEmpty();
  void clear();
  int length();

  char operator[](int index);
  void operator=(const char* str);
  void operator=(const StringQueue& obj);
  friend std::ostream &operator<<(std::ostream &out, const StringQueue& str);


  // Exceptions
  class OutOfBounds {};
  class Underflow {};
  class EnqueueMemErr {};

 private:
  class LetterNode {
    friend class StringQueue;
    char value;
    LetterNode* next;

    LetterNode(char newLetter, LetterNode* newNext = nullptr) {
      value = newLetter;
      next = newNext;
    }
  };
  LetterNode* front;
  LetterNode* rear;
  char strArray[];
};

#endif