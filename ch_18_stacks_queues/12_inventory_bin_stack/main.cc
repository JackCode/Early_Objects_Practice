#include <iostream>

#include "BinStack.h"
#include "Item.h"
#include "Date.h"

int main() {
  jw::BinStack warehouseA;
  jw::Item item;
  int choice = 3;
  int serialNum, lotNum;
  jw::Date manufactDate;

  do {
    std::cout << "1. Add part to inventory\n";
    std::cout << "2. Remove part from inventory\n";
    std::cout << "3. Exit\n\nEnter choice: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        std::cout << "Enter serial #: ";
        std::cin >> serialNum;
        std::cout << "Enter lot #: ";
        std::cin >> lotNum;
        std::cout << "Manufactered date (MM DD YYYY): ";
        std::cin >> manufactDate.month >> manufactDate.day >> manufactDate.year;
        try {
          item.setSerialNumber(serialNum);
          item.setLotNumber(lotNum);
          item.setManufactDate(manufactDate);
          warehouseA.push(item);
        } catch (jw::BinStack::PushMemError) {
          std::cout << "ERROR: Mem error. Try again\n";
        }
        break;
      case 2:
        try {
          item = warehouseA.top();
          warehouseA.pop();
        } catch (jw::BinStack::InvalidAccess) {
          std::cout << "No parts in inventory.\n";
          break;
        }
        std::cout << "Serial #: " << item.getSerialNumber() << "\n";
        std::cout << "Lot #: " << item.getLotNumber() << "\n";
        std::cout << "Manufacture Date: " << item.getDate() << "\n";
        std::cout << "\n";
        break;
      case 3:
        break;
      default:
        std::cout << "Invalid choice.\n";
        break;
    }
    std::cout << "\n";
  } while (choice != 3);

  return 0;
}