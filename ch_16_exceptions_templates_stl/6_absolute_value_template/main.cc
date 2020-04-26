#include <iostream>
#include <string>

template <class T>
T absoluteVal(T entry) {
  return (entry < 0) ? -1 * entry : entry;  
}

std::string absoluteVal(const char* entry) {
  return "Function requires numeric type.";
}

std::string absoluteVal(char entry) {
  return "Function requires numeric type.";
}

int main() {
  std::cout << absoluteVal(-29) << "\n";
  std::cout << absoluteVal(50.87) << "\n";
  std::cout << absoluteVal("Hello World") << "\n";
  std::cout << absoluteVal('a') << "\n";

  return 0;
}