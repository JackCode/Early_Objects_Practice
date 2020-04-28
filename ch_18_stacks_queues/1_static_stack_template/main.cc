#include <iostream>
#include <string>
#include "StaticStack.h"

int main() {
  int numItems, entryI;
  std::string entryS;

  std::cout << "How many integers to enter: ";
  std::cin >> numItems;

  StaticStack<int> intStack(numItems);

  for (int i = 0; i < numItems; i++) {
    std::cout << "Enter integer: ";
    std::cin >> entryI;
    
    try {
      intStack.push(entryI);
    } catch (StaticStack<int>::Overflow) {
      std::cout << "ERROR: overflow\n";
    }
  }

  for (int i = 0; i < numItems; i++) {
    try {
      intStack.pop(entryI);
      std::cout << entryI << " ";
    } catch (StaticStack<int>::Overflow) {
      std::cout << "ERROR: underflow\n";
    }
  }

  std::cout << "\n";

  std::cout << "How many words to enter: ";
  std::cin >> numItems;

  StaticStack<std::string> stringStack(numItems);

  for (int i = 0; i < numItems; i++) {
    std::cout << "Enter word: ";
    std::cin >> entryS;
    
    try {
      stringStack.push(entryS);
    } catch (StaticStack<std::string>::Overflow) {
      std::cout << "ERROR: overflow\n";
    }
  }

  for (int i = 0; i < numItems; i++) {
    try {
      stringStack.pop(entryS);
      std::cout << entryS << " ";
    } catch (StaticStack<std::string>::Overflow) {
      std::cout << "ERROR: underflow\n";
    }
  }

  std::cout << "\n";

  return 0;
}