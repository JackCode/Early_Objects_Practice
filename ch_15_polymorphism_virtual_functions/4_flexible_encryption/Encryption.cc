#include <iostream>

#include "Encryption.h"

// Constructors
Encryption::Encryption(char *inFileName, char *outFileName, int key) {
  inFile.open(inFileName);
  outFile.open(outFileName);
  
  if (!inFile) {
    std::cout << "Input file could not be opened.";
    exit(1);
  }

  if (!outFile) {
    std::cout << "Output file could not be opened.";
    exit(1);
  }

  this->encryptionKey = key;
}

// Destructor
Encryption::~Encryption() {
  inFile.close();
  outFile.close();
}

// Member Functions
void Encryption::encrypt() {
  char ch;
  char transCh;
  inFile.get(ch);
  while (!inFile.fail()) {
    transCh = transform(ch);
    outFile.put(transCh);
    inFile.get(ch);
  }
}