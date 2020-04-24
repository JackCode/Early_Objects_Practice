#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Date.h"

const int NAME_SIZE = 51, ADDRESS_SIZE = 51, CITY_SIZE = 51, STATE_SIZE = 3,
          TELEPHONE_SIZE = 14;

struct customer {
  char name[NAME_SIZE];
  char address[ADDRESS_SIZE];
  char city[CITY_SIZE];
  char state[STATE_SIZE];
  int zipCode;
  char telephone[TELEPHONE_SIZE];
  double accountBalance;
  date lastPayment;
};

#endif