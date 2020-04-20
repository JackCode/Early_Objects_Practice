#include <iostream>
#include <fstream>
#include <string>

int main() {
  const int NUM_LINES_TO_PRINT = 24,
            MAX_LINE_SIZE = 81;

  std::string fileName;
  char lineFromFile[MAX_LINE_SIZE];
  
  std::cout << "Enter file name: ";
  getline(std::cin, fileName);

  std::ifstream inputFile(fileName);
  if (!inputFile) {
    std::cout << "Error opening file.\n";
    return 0;
  }

  std::cout << "\n";

  while (true) {
    for (int i = 0; i < NUM_LINES_TO_PRINT; i++) {
      inputFile.getline(lineFromFile, 81);
      
      if (inputFile.fail()) {
        std::cout << "\n-- END OF FILE --\n";
        return 0;
      } else {
        std::cout << lineFromFile << "\n";
      }
    }
    std::cin.get();
  }
}