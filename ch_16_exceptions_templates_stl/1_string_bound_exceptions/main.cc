#include <iostream>

#include "BCheckString.h"

int main() {
  BCheckString message("Hello, World");

  try {
    for (int i = 0; i < message.length(); i++)
      std::cout << message[i];
  }
  catch (BCheckString::BoundsException e) {
    std::cout << "\nError: Out of bounds on index " << e.index << ".";
  }

  std::cout << "\n";

  try {
    for (int i = 0; i <= message.length(); i++)
      std::cout << message[i];
  }
  catch (BCheckString::BoundsException e) {
    std::cout << "\nError: Out of bounds on index " << e.index << ".";
  }

  std::cout << "\n";

  try {
    std::cout << message[-1];
  }
  catch (BCheckString::BoundsException e) {
    std::cout << "\nError: Out of bounds on index " << e.index << ".";
  }

  std::cout << "\n";

  return 0;
}