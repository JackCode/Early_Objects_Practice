#include <iostream>

#include "SimpleEncrypt.h"

int main() {
  char inFileName[80], outFileName[80];
  int encryptionKey;

  std::cout << "Input file: ";
  std::cin.getline(inFileName, 80);
  std::cout << "Output file: ";
  std::cin.getline(outFileName, 80);
  std::cout << "Enter integer encryption key: ";
  std::cin >> encryptionKey;

  SimpleEncrypt se(inFileName, outFileName, encryptionKey);
  se.encrypt();

  return 0;
}