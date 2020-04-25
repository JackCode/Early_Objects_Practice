#include <iostream>

#include "OddNumbers.h"
#include "TriangularNumbers.h"

int main() {
  AbstractSeq *odd = new OddNumbers;
  AbstractSeq *tri = new TriangularNumbers;

  odd->printSeq(0, 10);
  std::cout << "\nSum of above numbers: " << odd->sumSeq(0, 10) << "\n\n";

  tri->printSeq(0, 10);
  std::cout << "\nSum of above numbers: " << tri->sumSeq(0, 10) << "\n";


  return 0;
}