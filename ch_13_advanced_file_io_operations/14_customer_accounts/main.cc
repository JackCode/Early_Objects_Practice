#include <iostream>
#include <fstream>
#include <string>

#include "Menu.h"
#include "CustomerDatabase.h"

int main() {
  Menu menu;
  CustomerDatabase database("cust_accts.dat");
  std::string searchStr; 
  
  menu.print_menu();

  while (menu.get_menu_choice() != 6) {
    switch (menu.get_menu_choice()){
      case 1:
        database.new_record();
        break;
      case 2:
        std::cout << "Search for: ";
        getline(std::cin, searchStr);
        database.view_record(searchStr);
        break;
      case 3:
        std::cout << "Search for: ";
        getline(std::cin, searchStr);
        database.delete_record(searchStr);
        break;
      case 4:
        std::cout << "Search for: ";
        getline(std::cin, searchStr);
        database.modify_record(searchStr);
        break;
      case 5:
        database.display_all_records();
        break;
      default:
        std::cout << "Invalid input.";
        break;
    }

    menu.print_menu();
  }
  system("clear");
  std::cout << "Session ended. Logoff successful\n\n";
  return 0;
}