#include "NumDays.h"
#include <iostream>

#define HOURS_PER_DAY 8

// Constructor
NumDays::NumDays (const double& hoursWorked) {

    set_hours_worked(hoursWorked);
    
}

// Setters
void NumDays::set_hours_worked (const double& hoursWorked) {

    if ( hoursWorked < 0 )
        std::cout << "Invalid hours. Must be zero or more.\n";
    else
        this->hoursWorked = hoursWorked;

}

// Getters
double NumDays::get_hours_worked() {

    return this->hoursWorked;

}

double NumDays::get_days_worked() {

    return this->hoursWorked / HOURS_PER_DAY;

}

// Overloads
double NumDays::operator+ (const NumDays& addend) {

    return this->hoursWorked + addend.hoursWorked;

}

double NumDays::operator- (const NumDays& subtrahend) {

    return this->hoursWorked - subtrahend.hoursWorked;

}

NumDays NumDays::operator++ () {

    this->hoursWorked++;
    return *this;

}

NumDays NumDays::operator++ (int) {

    NumDays temp = *this;
    this->hoursWorked++;
    return temp;

}

NumDays NumDays::operator-- () {

    this->hoursWorked--;
    return *this;

}

NumDays NumDays::operator-- (int) {

    NumDays temp = *this;
    this->hoursWorked--;
    return temp;

}