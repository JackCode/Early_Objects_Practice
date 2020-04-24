#include <iostream>

#include "Menu.h"

Menu::Menu() {
  this->menuChoice = 6;
}

void Menu::print_menu() {
  system("clear");
  std::cout << "******************************\n";
  std::cout << "      Epic Rijks Sales\n";
  std::cout << "******************************\n";
  std::cout << "\n";

  std::cout << "  1. Enter new record\n";
  std::cout << "  2. Display record\n";
  std::cout << "  3. Delete record\n";
  std::cout << "  4. Modify record\n";
  std::cout << "  5. Display all records\n";
  std::cout << "  6. Logoff\n";
  std::cout << "\n";
  std::cout << "Enter selection [1-6]: ";
  std::cin >> this->menuChoice;

  while (this->menuChoice < 1 || this->menuChoice > 6) {
    std::cout << "-- INVALID ENTRY --\n";
    std::cout << "Enter selection [1-6]: ";
    std::cin >> this->menuChoice;
  }

  std::cin.ignore();
}

int Menu::get_menu_choice() {
  return this->menuChoice;
}