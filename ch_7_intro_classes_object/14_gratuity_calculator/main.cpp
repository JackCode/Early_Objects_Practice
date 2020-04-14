#include <iostream>
#include <iomanip>

#include "Tips.h"

using namespace std;

int main()
{

    int count = 0;
    double totalBill, tipRate;
    Tips myBill(0.065);

    cout << setprecision(2) << fixed;

    do
    {
        cout << "Enter bill amount: $";
        cin >> totalBill;
        cout << "Enter tip rate: ";
        cin >> tipRate;
        tipRate /= 100;

        cout << "Tip amount: $" << myBill.compute_tip(totalBill, tipRate);
        cout << "\n\n";

        count++;
    } while (count != 5);
    

    return 0;
}