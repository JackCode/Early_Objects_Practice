#include <iostream>
#include <cstring>

int main() {
  const int MAX_SIZE = 30;
  
  char firstName[MAX_SIZE];
  char middleName[MAX_SIZE];
  char lastName[MAX_SIZE];
  char fullName[MAX_SIZE+1] = ""; // 29 char for each name + comma + 2*space

  std::cout << "First name: ";
  std::cin.getline(firstName, MAX_SIZE);

  std::cout << "Middle name: ";
  std::cin.getline(middleName, MAX_SIZE);

  std::cout << "Last name: ";
  std::cin.get(lastName, MAX_SIZE);

  strcat(fullName, lastName);
  strcat(fullName, ", ");
  strcat(fullName, firstName);
  strcat(fullName, " ");
  strcat(fullName, middleName);

  std::cout << "\n" << fullName << "\n\n";

  return 0;
}