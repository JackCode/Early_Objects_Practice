#include "DayOfYear.h"

#include <iostream>
using namespace std;

// Static members
string DayOfYear::months[] {"", "January", "February", "March", "April", "May", "June",
                                "July", "August", "September", "October", "November", "December"};
int DayOfYear::daysPerMonth[] {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

// Instance members
DayOfYear::DayOfYear(int day) {

    if(day < 0 || day > 365)
    {
        cout << "Invalid. Must be 1-365\n";
        cout << "Setting default 1.\n";
        this->day = 1;
    } 
    else
    {
        this->day = day;
    }
    
}

void DayOfYear::print() {

    for (int i = 12; i >= 1; i--)
    {
        if(day > daysPerMonth[i])
        {
            cout << months[i] << " " << (day - daysPerMonth[i]);
            break;
        }
    }

}