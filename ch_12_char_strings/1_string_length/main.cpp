#include <iostream>
#include <string>

int get_length(char *ptr);

int main() {

  std::string input;

  std::cout << "Enter string: ";
  getline(std::cin, input);
  std::cout << "Length: " << get_length(&input[0]) << "\n";

  return 0;
}

int get_length(char *ptr) {
  int length = 0;
  char *str = ptr;

  while (*str != '\0') {
    length++;
    str++;
  }

  return length;
}