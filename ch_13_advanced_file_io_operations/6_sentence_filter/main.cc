#include <iostream>
#include <fstream>
#include <string>

void process_files(std::fstream&, std::fstream&);

int main() {
  std::string inFileName, outFileName;
  std::fstream inputFile, outputFile;

  std::cout << "Input file: ";
  getline(std::cin, inFileName);
  std::cout << "Output file: ";
  getline(std::cin, outFileName);

  inputFile.open(inFileName, std::ios::in);
  outputFile.open(outFileName, std::ios::out);

  if (!inputFile || !outputFile) {
    std::cout << "Error opening one of the files.\n";
    return 0;
  }

  process_files(inputFile, outputFile);

  return 0;
}

void process_files(std::fstream& inputFile, std::fstream& outputFile) {
  char ch;

  inputFile.get(ch);
  outputFile.put(toupper(ch));
  inputFile.get(ch);

  while (!inputFile.fail()) {
    if (ch == '.') {
      while (!isalpha(ch) && !inputFile.fail()) {
        outputFile.put(ch);
        inputFile.get(ch);
      }
      outputFile.put(toupper(ch));
      inputFile.get(ch); 
    } else {
      outputFile.put(tolower(ch));
      inputFile.get(ch);
    }
  }
}