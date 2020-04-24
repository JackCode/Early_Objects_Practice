#include <cstring>
#include <stdlib.h>
#include <iomanip>

#include "CustomerDatabase.h"

// Constructor
CustomerDatabase::CustomerDatabase(const std::string &dataFileName) {
  this->dataFileName = dataFileName;
  read_all_records();
}

// Destructor
CustomerDatabase::~CustomerDatabase() {
  write_all_records();
}

// Public Member Functions
void CustomerDatabase::new_record() {
  customer tempRecord;

  system("clear");
  std::cout << " -- NEW RECORD --\n";
  std::cout << "\n";
  std::cout << "Name (Last, First M): ";
  std::cin.getline(tempRecord.name, NAME_SIZE);
  std::cout << "Address: ";
  std::cin.getline(tempRecord.address, ADDRESS_SIZE);
  std::cout << "City: ";
  std::cin.getline(tempRecord.city, CITY_SIZE);
  std::cout << "State (XX): ";
  std::cin.getline(tempRecord.state, STATE_SIZE);
  std::cout << "Zip (XXXXX): ";
  std::cin >> tempRecord.zipCode;
  std::cin.ignore();
  std::cout << "Phone: ";
  std::cin.getline(tempRecord.telephone, TELEPHONE_SIZE);
  std::cout << "Account balace: $";
  std::cin >> tempRecord.accountBalance;
  std::cout << "Date of last payment (MM DD YYYY): ";
  std::cin >> tempRecord.lastPayment.month >> tempRecord.lastPayment.day
           >> tempRecord.lastPayment.year;
  customers.push_back(tempRecord);
  write_all_records();  
}

void CustomerDatabase::view_record(const std::string &needle) {
  int person = find_record(needle);
  
  if (person == -1) {
    system("clear");
    std::cout << "Record not found.";
    std::cout << "\nPress enter to continue...";
    std::cin.get();
    return;
  }

  system("clear");
  display_record(customers[person]);
  std::cout << "\nPress enter to continue...";
  std::cin.get();
}

void CustomerDatabase::delete_record(const std::string &needle) {
  int person = find_record(needle);
  char confirmDelete;
  
  if (person == -1) {
    system("clear");
    std::cout << "Record not found.";
    std::cout << "\nPress enter to continue...";
    std::cin.get();
    return;
  }

  system("clear");
  display_record(customers[person]);
  std::cout << "Are you sure you want to delete this customer? (Y/n): ";
  std::cin >> confirmDelete;

  if (confirmDelete == 'y' || confirmDelete == 'Y') {
    customers.erase(customers.begin() + person);
    std::cout << "Customer deleted.\n";
  } else {
    std::cout << "Delete operation cancelled.\n";
  }

  std::cout << "\nPress enter to continue...";
  std::cin.get();
}

void CustomerDatabase::modify_record(const std::string &needle) {
  int person = find_record(needle);
  int modifyField;
  
  if (person == -1) {
    system("clear");
    std::cout << "Record not found.";
    std::cout << "\nPress enter to continue...";
    std::cin.get();
    return;
  }

  system("clear");
  display_record(customers[person]);
  std::cout << "\n";
  std::cout << "1. Name   2. Address   3. City   4. State   5. Zip\n"
            << "6. Phone  7. Account balance     8. Last Payment Date\n\n";
  std::cout << "Choose field to modify (0 to cancel): ";
  std::cin >> modifyField;
  std::cin.ignore();

  if (modifyField < 1 || modifyField > 8) {
    std::cout << "Modify Operation Cancelled.\n";
    std::cout << "Press enter to continue...";
    std::cin.get();
    return;
  }

  switch (modifyField) {
    case 1:
      std::cout << "Name (Last, First M): ";
      std::cin.getline(customers[person].name, NAME_SIZE);
      break;
    case 2:
      std::cout << "Address: ";
      std::cin.getline(customers[person].address, ADDRESS_SIZE);
      break;
    case 3:
      std::cout << "City: ";
      std::cin.getline(customers[person].city, CITY_SIZE);
      break;
    case 4:
      std::cout << "State (XX): ";
      std::cin.getline(customers[person].state, STATE_SIZE);
      break;
    case 5:
      std::cout << "Zip (XXXXX): ";
      std::cin >> customers[person].zipCode;
      std::cin.ignore();
      break;
    case 6:
      std::cout << "Phone: ";
      std::cin.getline(customers[person].telephone, TELEPHONE_SIZE);
      break;
    case 7:
      std::cout << "Account balace: $";
      std::cin >> customers[person].accountBalance;
      std::cin.ignore();
      break;
    case 8:
      std::cout << "Date of last payment (MM DD YYYY): ";
      std::cin >> customers[person].lastPayment.month 
               >> customers[person].lastPayment.day
               >> customers[person].lastPayment.year;
      std::cin.ignore();
      break;
    default:
      std::cout << "Modify Operation Cancelled.";
      break;
  }

  std::cout << "\nPress enter to continue...";
  std::cin.get();
}

void CustomerDatabase::display_all_records() {
  system("clear");
  std::cout << " -- ALL RECORDS --\n";
  std::cout << "\n";
  
  for (const customer &cust: customers) {
    display_record(cust);
    std::cout << "\n";
  }

  std::cout << "\nPress enter to continue...";
  std::cin.get();
}

// Private Member Functions
void CustomerDatabase::open_file(std::ios_base::openmode mode) {
  this->dataFile.open(this->dataFileName, mode  | std::ios::binary);

  while (!this->dataFile) {
    std::cout << "Error opening file.\n";
    std::cout << "Enter file name: ";
    getline(std::cin, this->dataFileName);
    this->dataFile.open(this->dataFileName, mode | std::ios::binary);
  }
}

void CustomerDatabase::close_file() {
  this->dataFile.close();
}


void CustomerDatabase::read_all_records() {
  customer tempCustomer;
  open_file(std::ios::in);

  dataFile.read(reinterpret_cast<char *>(&tempCustomer), this->sizeOfRecord);
  while(!dataFile.eof()) {
    customers.push_back(tempCustomer);
    dataFile.read(reinterpret_cast<char *>(&tempCustomer), this->sizeOfRecord);
  }
  
  close_file();

  this->numStoredRecords = customers.size();
}

void CustomerDatabase::write_all_records() {
  open_file(std::ios::out);

  for (customer &cust : customers) 
    dataFile.write(reinterpret_cast<char *>(&cust), sizeOfRecord);

  close_file();
}

int CustomerDatabase::find_record(const std::string &needle) {
  char confirm;
  int custIndex = 0;
  system("clear");

  for (const customer &cust: customers) {
    if(strstr(cust.name, needle.c_str()) != nullptr ||
       strstr(cust.address, needle.c_str()) != nullptr ||
       strstr(cust.city, needle.c_str()) != nullptr ||
       strstr(cust.state, needle.c_str()) != nullptr ||
       strstr(cust.telephone, needle.c_str()) != nullptr) {
      display_record(cust);
      std::cout << "\n";
      std::cout << "This Records? (Y/n): ";
      std::cin >> confirm;
      if (confirm == 'Y' || confirm == 'y') {
        std::cin.ignore();
        return custIndex;
      }
        
    }
      
    system("clear");
    custIndex++;  
  }
  return -1;
}

void CustomerDatabase::display_record(const customer& cust) {
  std::cout << cust.name << "\n";
  std::cout << cust.address << "\n";
  std::cout << cust.city << ", " << cust.state << " " << cust.zipCode << "\n";
  std::cout << cust.telephone << "\n";
  std::cout << std::setprecision(2) << std::fixed;
  std::cout << "Account Balance: $" << cust.accountBalance << "\n";
  std::cout << std::setprecision(0);
  std::cout << "Last payment: " 
            << cust.lastPayment.month << "/"
            << cust.lastPayment.day << "/"
            << cust.lastPayment.year
            << "\n";
}
