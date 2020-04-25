#ifndef ABSTRACT_SEQ_H_
#define ABSTRACT_SEQ_H_

class AbstractSeq {
 public:
  virtual int fun(int k) =0;
  void printSeq(int k, int m);
  int sumSeq(int k, int m);
};


#endif