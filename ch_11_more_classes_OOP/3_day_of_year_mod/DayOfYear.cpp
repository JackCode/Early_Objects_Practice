#include "DayOfYear.h"

#include <iostream>
#include <cctype>
using namespace std;

// Static members
string DayOfYear::months[] {"", "January", "February", "March", "April", "May", "June",
                                "July", "August", "September", "October", "November", "December"};
int DayOfYear::daysPerMonth[] {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

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

DayOfYear::DayOfYear(string month, int day) {

    for(int m = 1; m <= 12; m++)
    {
        if (month == months[m])
        {
            if (daysPerMonth[m] + day > daysPerMonth[m + 1] || day < 1)
            {
                cout << "Day outside month range.\n";
                cout << "Setting January 1st.\n";
                this->day = 1;
                break;
            }
            else
            {
                this->day = daysPerMonth[m] + day;            
                break;
            }
        }
        else if (m == 12)
        {
            cout << "Month not found\n";
            cout << "Setting January 1st.\n";
            this->day = 1;
        }
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

// Overloads
DayOfYear DayOfYear::operator++() {
    this->day++;

    if (this->day == 366)
        this->day = 1;

    return *this;
}

DayOfYear DayOfYear::operator++(int) {
    
    DayOfYear temp = *this;
    this->day++;
    return temp;

}