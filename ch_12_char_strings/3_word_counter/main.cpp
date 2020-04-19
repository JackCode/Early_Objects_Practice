#include <iostream>
#include <cstring>

int count_words(char *ptr);

int main() {

  const int MAX_SIZE = 30;
  char message[MAX_SIZE];

  std::cout << "Enter string: ";
  std::cin.getline(message, MAX_SIZE);

  std::cout << "Number of words: " << count_words(message);
  std::cout << "\n";
  return 0;
}

int count_words(char *ptr) {
  int wordCount = 0;

  while (*ptr != '\0') {
    if (isalpha(*ptr) && (isspace(*(ptr+1)) || *(ptr+1) == '\0' || ispunct(*(ptr+1)))) {
      wordCount++;
    }
    ptr++;
  }

  return wordCount;
}