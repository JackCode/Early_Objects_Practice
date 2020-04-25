#ifndef TRIANGULAR_NUMBERS_H_
#define TRIANGULAR_NUMBERS_H_

#include "AbstractSeq.h"

class TriangularNumbers : public AbstractSeq {
 public:
  virtual int fun(int k) { return k * (k + 1) / 2; }
};

#endif