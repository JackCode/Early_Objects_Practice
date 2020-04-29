#include <iostream>

#include "StringQueue.h"

int main() {
  char temp;
  StringQueue str; 
  str = "One";
  std::cout << str << "\n";
  std::cout << "Length: " << str.length() << "\n";

  StringQueue str2;
  str2 = "Four";
  std::cout << str2 << "\n";
  std::cout << "Length: " << str2.length() << "\n";

  str2 = "Hello, World!";
  for (int i = 0; i < str2.length(); i++) {
    std::cout << str2[i];
  }

  std::cout << "\n";
  return 0;
}