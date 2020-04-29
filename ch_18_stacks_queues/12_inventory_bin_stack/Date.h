#ifndef DATE_H_
#define DATE_H_

#include <iostream>

namespace jw {

class Date {
 public:
  Date() {
    day = 0;
    month = 0;
    year = 0;
  }

  Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
  }

  friend std::ostream& operator<<(std::ostream &out, const Date &date);
  int day;
  int month;
  int year;
};

inline std::ostream& operator<<(std::ostream &out, const Date &date) {
  out << date.month << "/" << date.day << "/" << date.year;
  return out; 
}

}

#endif