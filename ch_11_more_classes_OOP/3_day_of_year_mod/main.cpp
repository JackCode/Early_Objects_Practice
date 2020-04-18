#include <iostream>
#include <string>
#include "DayOfYear.h"

using namespace std;

int main() {

    int day;
    string month;

    cout << "Enter month and day : ";
    cin >> month >> day;

    DayOfYear *ptr = new DayOfYear(month, day);
    cout << "Incrementing date twice..." << endl;
    (*ptr)++;
    ++(*ptr);

    cout << endl;
    ptr->print();
    cout << endl << endl;

    delete ptr;


    return 0;
}