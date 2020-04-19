#include <iostream>
#include <cstring>

int get_num_vowels(char* message);
int get_num_consonants(char* message);

int main () {
  const int MAX_SIZE = 50;
  char message[MAX_SIZE];

  std::cout << "Enter a sentence: ";
  std::cin.getline(message, MAX_SIZE);
  std::cout << "\nThe sentence \"" << message << "\" has "
            << get_num_vowels(message) << " vowels and "
            << get_num_consonants(message) << " consonants.\n";

  return 0;
}

int get_num_vowels(char* message) {
  int vowelCount = 0;

  while (*message != '\0') {
    if (tolower(*message) == 'a' || tolower(*message) == 'e' || 
        tolower(*message) == 'i' || tolower(*message) == 'o' || 
        tolower(*message) == 'u' ) {
        vowelCount++;
    }
    message++;
  } 

  return vowelCount;
}

int get_num_consonants(char* message) {
  int letterCount = 0;
  int vowelCount = get_num_vowels(message);

  while (*message != '\0') {
    if (isalpha(*message)) letterCount++;
    message++;
  }

  return letterCount-vowelCount;
}