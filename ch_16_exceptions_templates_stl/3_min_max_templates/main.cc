#include <iostream>

template <class T>
T min (T a, T b) {
  return (a > b) ? b : a; 
}

template <class T>
T max (T a, T b) {
  return (a < b) ? b : a; 
}

int main() {
  int a = 1, b = 2, c = 3;
  double x = 4.5, y = 5.7, z = 8.9;

  std::cout << min(a, b) << "\n";
  std::cout << min(x, y) << "\n";
  std::cout << "\n";
  std::cout << max(c, b) << "\n";
  std::cout << max(z, y);
  std::cout << "\n";

  return 0;
}