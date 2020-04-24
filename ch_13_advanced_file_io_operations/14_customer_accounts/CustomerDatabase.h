#ifndef CUSTOMER_DATABASE_H
#define CUSTOMER_DATABASE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Customer.h"

class CustomerDatabase {
 public:
  CustomerDatabase(const std::string &dataFileName);
  ~CustomerDatabase();

  void new_record();
  void view_record(const std::string &needle);
  void delete_record(const std::string &needle);
  void modify_record(const std::string &needle);
  void display_all_records();

 private:
  std::string dataFileName;
  std::fstream dataFile;
  std::vector<customer> customers;
  int sizeOfRecord = sizeof(customer);
  int numStoredRecords;

  void open_file(std::ios_base::openmode mode);
  void close_file();
  void read_all_records();
  void write_all_records();
  int find_record(const std::string &needle);
  void display_record(const customer &cust);
};

#endif