// Non-recursive function to find factorial.

#include <iostream>

// Probably bad to use ull, but jsut playing aorund
unsigned long long factorial(int number);

int main() {
  int input;

  std::cout << "Enter number to find factorial: ";
  std::cin >> input;

  std::cout << input << "! = " << factorial(input) << "\n";

  return 0;
}

unsigned long long factorial(int number) {
  unsigned long long factorial = number;
  number--;
  
  if (factorial < 0) {
    return -1;
  } else if (factorial == 0) {
    return 1;
  } else {
    while (number > 0) {
      factorial *= number;
      number--;
    }
    return factorial;
  }
}