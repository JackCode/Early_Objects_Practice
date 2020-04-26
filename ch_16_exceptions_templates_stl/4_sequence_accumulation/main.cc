#include <iostream>
#include <vector>

template <class T>
T accum(std::vector<T> v) {
  T sum = T();
  for (const T &entry: v)
    sum += entry;
  return sum;
}

int main() {
  std::vector<int> intVector;
  std::vector<std::string> stringVector;
  int tempInt; std::string tempString;
  
  for (int i = 0; i < 3; i++) {
    std::cout << "Enter integer: ";
    std::cin >> tempInt;
    intVector.push_back(tempInt);
  }
  std::cout << "The sum of the integers you entered is: "
            << accum(intVector) << "\n\n";
  std::cin.ignore();

  for (int i = 0; i < 3; i++) {
    std::cout << "Enter string: ";
    getline(std::cin, tempString);
    stringVector.push_back(tempString);
  }
  std::cout << "Your strings concatenated: "
            << accum(stringVector) << "\n\n";

  return 0;
}