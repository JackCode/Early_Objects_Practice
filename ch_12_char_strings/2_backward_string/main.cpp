#include <iostream>
#include <cstring>

void display_backwards(char *ptr);

int main() {

  const int MAX_SIZE = 30;
  char message[MAX_SIZE];

  std::cout << "Enter string: ";
  std::cin.getline(message, MAX_SIZE);

  display_backwards(message);
  std::cout << "\n";
  return 0;
}

void display_backwards(char *ptr) {

  int length = strlen(ptr);

  for (int i = length-1; i >= 0; i--)
    std::cout << ptr[i];

}