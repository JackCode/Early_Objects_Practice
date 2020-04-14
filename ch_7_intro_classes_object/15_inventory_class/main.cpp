#include <iostream>
#include <iomanip>
#include "Inventory.h"

using namespace std;

int main()
{
    int numItems, tempItemNum = 0, tempQuantity = 0;
    double tempCost = 0;

    cout << "How many items: ";
    cin >> numItems;

    cout << setprecision(2) << fixed;

    Inventory myItems[numItems];

    for(int i = 0; i < numItems; i++)
    {

        cout << "\nEnter Item #" << (i+1) << endl;
        cout << "-----------------------\n";
        cout << "Item Number: ";
        cin >> tempItemNum;
        cout << "Quantity: ";
        cin >> tempQuantity;
        cout << "Cost: $";
        cin >> tempCost;
        
        myItems[i].setItemNumber(tempItemNum);
        myItems[i].setQuantity(tempQuantity);
        myItems[i].setCost(tempCost);
        myItems[i].setTotalCost();

        cout << "Total cost for item #" << myItems[i].getItemNumber() << ": $" << myItems[i].getTotalCost() << endl;
    }

    cout << "\n";
    return 0;
}