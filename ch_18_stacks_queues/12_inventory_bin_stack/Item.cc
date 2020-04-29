#include "Item.h"
#include "Date.h"

// Constructors
jw::Item::Item() {
  this->serialNum = 0;
  this->manufactDate = Date();
  this->lotNum = 0;
}
jw::Item::Item (int serialNum, jw::Date &setManufactDate, int lotNum) {
  this->serialNum = serialNum;
  this->manufactDate.day = manufactDate.day;
  this->manufactDate.month = manufactDate.month;
  this->manufactDate.year = manufactDate.year;
  this->lotNum = lotNum;
}

// Set Serial Number
void jw::Item::setSerialNumber(const int &serialNum) {
  this->serialNum = serialNum;
}
  
// Set Manufactured Date
void jw::Item::setManufactDate(const jw::Date &manufactDate) {
  this->manufactDate.day = manufactDate.day;
  this->manufactDate.month = manufactDate.month;
  this->manufactDate.year = manufactDate.year;
}

// Set Lot Number
void jw::Item::setLotNumber(const int &lotNum) {
  this->lotNum = lotNum;
}