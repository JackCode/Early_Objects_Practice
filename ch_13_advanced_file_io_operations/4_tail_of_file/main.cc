#include <iostream>
#include <fstream>
#include <string>

int get_num_lines(std::ifstream& inputFile);

int main() {
  std::string fileName;
  std::string buffer;
  char ch;
  int lineCount = 0;

  std::cout << "Enter file name: ";
  getline(std::cin, fileName);

  std::ifstream inputFile(fileName);
  if (!inputFile) {
    std::cout << "Error opening file.\n";
    return 0;
  }

  inputFile.seekg(-1L, std::ios::end);
  ch = inputFile.peek();

  while (lineCount != 10 && inputFile.tellg() != 0L) { // Backup 10 lines
    if (ch == '\n') lineCount++;
  
    inputFile.seekg(-1L, std::ios::cur);
    ch = inputFile.peek();
  }

  if (inputFile.tellg() == 0l)
    std::cout << "\n";
  else 
    inputFile.seekg(1L, std::ios::cur);

  while (lineCount >= 0) {  // Print ten lines
    getline(inputFile, buffer);
    std::cout << buffer << std::endl;
    lineCount--;
  }

  std::cout << "\n";

  return 0;
}