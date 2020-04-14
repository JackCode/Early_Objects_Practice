#include <iostream>
#include <iomanip>
#include <string>

#include "Heading.h"

using namespace std;

void Heading::print_one_line() 
{
    cout << companyName << " " << reportName;
}

void Heading::print_box_report()
{
    cout <<      "*********************************************\n"
         << setw(22 + (companyName.length() / 2)) << companyName << "\n"
         << setw(22 + (reportName.length() / 2)) << reportName << "\n"
         <<      "*********************************************\n";
}