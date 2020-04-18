#include <iostream>
#include "DayOfYear.h"

using namespace std;

int main() {

    int input;

    while (true)
    {
        cout << "Enter day of year (1-365): ";
        cin >> input;

        DayOfYear *ptr = new DayOfYear(input);

        cout << endl;
        ptr->print();
        cout << endl << endl;

        delete ptr;
    }

    return 0;
}