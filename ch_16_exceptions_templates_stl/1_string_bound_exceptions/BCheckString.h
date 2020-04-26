#ifndef B_CHECK_STRIN_H_
#define B_CHECK_STRIN_H_

#include <string>

class BCheckString : public std::string {
 public:
  BCheckString(std::string s) : std::string(s){}
  char operator[](int k);

  class BoundsException{
   public:
    BoundsException(int index) { this->index = index; }
    int index;
  };
};


#endif