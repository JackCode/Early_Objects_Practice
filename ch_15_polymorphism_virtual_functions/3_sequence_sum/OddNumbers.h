#ifndef ODD_NUMBERS_H_
#define ODD_NUMBERS_H_

#include "AbstractSeq.h"

class OddNumbers : public AbstractSeq {
 public:
  virtual int fun(int k) { return 2 * k + 1; }
};


#endif