#ifndef SIMPLE_ENCRYPT_H_
#define SIMPLE_ENCRYPT_H_

#include "Encryption.h"

class SimpleEncrypt : public Encryption {
 public:
  SimpleEncrypt(char *inFileName, char *outFileName, int key) 
  : Encryption(inFileName, outFileName, key){}
 
 private:
  virtual char transform(char ch) { return ch + this->get_encryptionKey(); }
};


#endif