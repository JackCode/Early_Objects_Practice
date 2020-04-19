#include <iostream>
#include <string>

char most_freq(const std::string& input);

int main() {

  std::string input;

  std::cout << "Enter phrase, word, or sentence: ";
  getline(std::cin, input);
  std::cout << "\n" << "Most Freq Character: \"" << most_freq(input) << "\"\n\n"; 

  return 0;
}

// This solution only searches the string for characters that exist in the string,
// not all ASCII characters.
char most_freq(const std::string& input) {
  const int INPUT_LENGTH = input.length();
  char freqLetter, currentLetter;
  int freqLetterCount = 0, 
      currentLetterCount = 0, 
      searchPos = 0;

  for (int i = 0; i < INPUT_LENGTH; i++) {  // Loop through input string
    currentLetter = input[i];

    if (input.find(currentLetter, 0) == i) {  // If current letter hasn't been searched for yet
      currentLetterCount = 1;
      searchPos = i+1;
    
      while (input.find(currentLetter, searchPos) < INPUT_LENGTH && searchPos < INPUT_LENGTH) { // If you find it
        currentLetterCount++;
        searchPos = input.find(currentLetter, searchPos) + 1; // Only search after current find
      }

      if (currentLetterCount > freqLetterCount) {
        freqLetterCount = currentLetterCount;
        freqLetter = currentLetter;
      }
    }
  }

  return freqLetter;
}