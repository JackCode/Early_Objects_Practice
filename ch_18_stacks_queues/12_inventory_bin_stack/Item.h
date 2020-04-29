#ifndef ITEM_H_
#define ITEM_H_

#include "Date.h"

namespace jw {

class Item {
 public:
  Item();
  Item(int serialNum, jw::Date &setManufactDate, int lotNum);

  // Setters
  void setSerialNumber(const int &serialNum);
  void setManufactDate(const jw::Date &manufactDate);
  void setLotNumber(const int &lotNum);

  // Getters
  int getSerialNumber() { return serialNum; }
  jw::Date getDate() { return manufactDate; }
  int getLotNumber() { return lotNum; }

 private:
  int serialNum;
  jw::Date manufactDate;
  int lotNum;
};

}

#endif