#include <iostream>
#include <fstream>
#include <iomanip>
#include "payroll.h"
using namespace std;

int main() {

    PayRoll employees[7];
    double rate, hours;
    int count = 0;

    ifstream inputFile;
    inputFile.open("payroll.dat");

    cout << setprecision(2) << fixed;

    if(!inputFile)
    {
        cout << "Error opening file.";
        return 0;
    }
    else
    {
        while(inputFile >> hours >> rate)
        {
            employees[count].set_worker_info(rate, hours);
            count++;
        }

        for(int i = 0; i < 7; i++)
            cout << "Employee #" << (i+1) << " gross pay: $" << employees[i].get_gross_pay() << endl;
        
    }
    
    cout << endl;

    return 0;
}