#include <iostream>

#include "AbstractSeq.h"

void AbstractSeq::printSeq(int k, int m) {
  for (int i = k; i < m; i++)
    std::cout << fun(i) << " ";
}

int AbstractSeq::sumSeq(int k, int m) {
  int sum = 0;

  for (int i = k; i < m; i++)
    sum += fun(i);

  return sum;
}