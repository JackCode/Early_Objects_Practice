#include "BCheckString.h"

char BCheckString::operator[](int k) {
  std::string s = this->data();
  if (k < 0 || k > s.length()-1)
    throw BoundsException(k);
  else
    return s[k];
}