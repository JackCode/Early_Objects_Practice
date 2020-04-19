#include <iostream>
#include <string>
#include <sstream>

int count_digits(const std::string& input);

int main() {

  std::string input;

  std::cout << "Enter ID number: ";
  std::cin >> input;

  std::cout << "The sum of the digits in " << input << " is " << count_digits(input) << "\n"; 

  return 0;
}

int count_digits(const std::string& input) {
  std::istringstream istr(input);
  int inputAsInt, sum = 0;
  istr >> inputAsInt;

  while (inputAsInt != 0) {
    sum += inputAsInt % 10;
    inputAsInt /= 10;
  }

  return sum;
}