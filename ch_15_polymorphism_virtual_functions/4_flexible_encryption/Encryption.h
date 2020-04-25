#ifndef ENCRPYTION_H_
#define ENCRYPTION_H_

#include <iostream>
#include <fstream>

class Encryption {
 public:
  Encryption(char *inFileName, char *outFileName, int key);
  ~Encryption();

  void encrypt();
  void set_encryptionKey(int key) { this->encryptionKey = key; }

 protected:
  std::ifstream inFile;
  std::ofstream outFile;
  int get_encryptionKey() { return this->encryptionKey; }

  // Pure virtual function
  virtual char transform(char ch) =0;

 private:
  int encryptionKey;
};


#endif