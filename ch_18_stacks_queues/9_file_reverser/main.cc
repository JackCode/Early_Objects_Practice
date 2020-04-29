#include <iostream>
#include <stack>
#include <fstream>

int main() {
  std::ifstream inputFile;
  std::ofstream outputFile;
  std::string fileName;
  std::stack<char> charStack;
  char ch;

  std::cout << "This program will reverse a file\'s contents.\n"
            << "Enter file name: ";
  getline(std::cin, fileName);

  inputFile.open(fileName);
  outputFile.open("output.txt");

  while (!inputFile) {
    std::cout << "File not found.\n"
              << "Enter file name: ";
    getline(std::cin, fileName);
  }

  inputFile.get(ch);

  while (!inputFile.eof()) {
    charStack.push(ch);
    inputFile.get(ch);
  }

  while (!charStack.empty()) {
    outputFile << charStack.top();
    charStack.pop();
  }

  std::cout << "You file has been reversed and saved to \"output.txt\".\n";

  return 0;
}