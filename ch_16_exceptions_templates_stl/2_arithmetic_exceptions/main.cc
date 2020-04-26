#include <iostream>
#include <cmath>

int sq_root(int x);

int main() {

  try {
    std::cout << sq_root(81) << "\n";
  } catch (char *exString) {
    std::cout << exString << "\n";
  }

  try {
    std::cout << sq_root(-7) << "\n";
  } catch (char const *exString) {
    std::cout << exString << "\n";
  }

 try {
    std::cout << sq_root(15) << "\n";
  } catch (char const *exString) {
    std::cout << exString << "\n";
  }

  return 0;
}

int sq_root(int x) {
  double result;
  
  if (x < 0)
    throw "ERROR: Function does not accept negative numbers.";
  else
    result = sqrt(static_cast<double>(x));

  if (result * result != x)
    throw "ERROR: Input is not a perfect square.";
  else
    return static_cast<int>(result);
}