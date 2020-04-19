#include <iostream>
#include <iomanip>
#include "DivSales.h"
using namespace std;

#define NUM_DIVISIONS 6

void sales_report(DivSales region[]);

int main() {

    DivSales america[NUM_DIVISIONS];
    double quarter[NUM_PERIODS];

    for ( int division = 0; division < NUM_DIVISIONS; division++ )
    {
        do
        {
            for ( int qtr = 0; qtr < NUM_PERIODS; qtr++ )
            {
                cout << "Division " << division+1 << ", Quarter " << qtr+1 << ": $";
                cin >> quarter[qtr];
            }

            if ( quarter[0] < 0 || quarter[1] < 0 || quarter[2] < 0 || quarter[3] < 0 )
                cout << "Invalid entry. Must be positive sales.\n\n";

        } while (quarter[0] < 0 || quarter[1] < 0 || quarter[2] < 0 || quarter[3] < 0);

        america[division].set_quarterly_sales(quarter[0], quarter[1], quarter[2], quarter[3]);
    }

    sales_report(america);
    cout << endl;

    return 0;
}

void sales_report(DivSales region[]) {

    system("clear");

    int quarter;

    cout << setw(43) << "Region\'s Sales\n";
    cout << "------------------------------------------------------------------\n";
    cout << setw(13) << " ";
    
    for ( quarter = 0; quarter < NUM_PERIODS; quarter++ )
    {
        cout << setw(9) << "Quarter " << quarter+1 << "    ";
    }
    
    cout << endl;

    for ( int reg = 0; reg < NUM_DIVISIONS; reg++ )
    {
        cout << setprecision(0) << fixed;
        cout << "Division " << (reg+1);

        cout << setprecision(2) << fixed;
        for ( quarter = 0; quarter < NUM_PERIODS; quarter++ )
        {
            cout << "   $" << setw(10) << region[reg].get_specified_qtr_sales(quarter);
        }
        
        cout << endl;
    }

    cout << endl;

    cout << "Total Regional Sales: $" << region[0].get_region_sales() << endl;

}