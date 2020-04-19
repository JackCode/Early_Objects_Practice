#include "DivSales.h"
#include <iostream>
using namespace std;

// Defining static members
double DivSales::regionSales = 0;

// Constructors
DivSales::DivSales() {

    set_quarterly_sales(0, 0, 0, 0);

}

DivSales::DivSales(const double &q1, const double &q2, const double &q3, const double &q4) {
    
    set_quarterly_sales(q1, q2, q3, q4);

}

// Setters
void DivSales::set_quarterly_sales(const double &q1, const double &q2, const double &q3, const double &q4) {

    this->quarterlySales[0] = q1;
    this->quarterlySales[1] = q2;
    this->quarterlySales[2] = q3;
    this->quarterlySales[3] = q4;

    regionSales += (q1 + q2 + q3 + q4);

}

// Getters
double DivSales::get_specified_qtr_sales(const int &qtr) {

    if (qtr < 0 || qtr > 3)
    {
        cout << "Invalid quarter.\n";
        return -1;
    }
    else
    {
        return quarterlySales[qtr];
    }
    
}

