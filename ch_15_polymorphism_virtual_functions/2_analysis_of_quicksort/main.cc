#include <iostream>

#include "QuickSort.h"

int main() {
  QuickSort qs;
  const int ARRAY_SIZE = 10;
  int array[ARRAY_SIZE] {17, 53, 9, 2, 30, 1, 82, 64, 26, 5};

  for (int i = 0; i < 10; i++)
  std::cout << array[i] << " ";

  std::cout << "\n";

  qs.sort(array, ARRAY_SIZE);

  for (int i = 0; i < 10; i++)
  std::cout << array[i] << " ";

  std::cout << "\n";
  std::cout << "Number of comparisons: " << qs.get_num_compares() << "\n";

  return 0;
}