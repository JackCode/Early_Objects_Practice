#include <iostream>
#include <fstream>
#include <string>

void string_search(std::ifstream& inputFile, const std::string& needle);

int main() {

  std::ifstream inputFile;
  std::string fileName, searchString;

  std::cout << "Enter file name: ";
  getline(std::cin, fileName);

  inputFile.open(fileName);

  if(!inputFile) {
    std::cout << "Error opening file.\n";
    return 0;
  }

  std::cout << "Enter text to search for: ";
  getline(std::cin, searchString);

  string_search(inputFile, searchString);

  return 0;
}

void string_search(std::ifstream& inputFile, const std::string& needle) {
  int foundCount = 0;
  std::string haystack;

  getline(inputFile, haystack);

  while (!inputFile.fail()) {
    if (haystack.find(needle, 0) < haystack.size()) { // Uncertain about this
      std::cout << haystack << "\n";
      foundCount++;
    }

    getline(inputFile, haystack);
  }
  std::cout << "Text found " << foundCount << " times\n";
}