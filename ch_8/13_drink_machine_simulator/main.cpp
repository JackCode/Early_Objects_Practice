#include <iostream>
#include "drink_machine.h"
using namespace std;

int print_menu();
int get_beverage(double&);

int main() {

    DrinkMachine office;
    int choice, beverage;
    double money = 0.0;
    
    system("clear");

    do
    {
        choice = 0;

        switch(print_menu())
        {
            case 1:
                system("clear");
                office.display_choices();
                cout << endl;
                break;
            case 2:
                beverage = get_beverage(money);
                office.buy_drink(beverage, money);
                cout << endl;
                break;
            case 3:
                choice = 3;
                system("clear");
                break;
            default:
                cout << " -- INVALID OPTION --\n";
                break;
        }
    } while (choice != 3);
    

    return 0;
}

int print_menu() {

    int choice;

    cout << "SODA MACHINE\n\n";

    cout << "1. Display Choices\n"
         << "2. Buy Soda\n"
         << "3. Leave\n\n";

    cout << "Enter choice: ";
    cin >> choice;

    return choice;
}

int get_beverage(double& m)
{
    int b;
    
    do
    {
        cout << "Select beverage: ";
        cin >> b;

        if (b < 1 || b > 5)
            cout << "-- INVALID BEVERAGE CHOICE --\n";

    } while (b < 1 || b > 5);

    do
    {
        cout << "Enter payment: ";
        cin >> m;

        if (m < 0)
            cout << "-- INVALID PAYMENT --";

    } while (m < 0);
    
    return b;

}