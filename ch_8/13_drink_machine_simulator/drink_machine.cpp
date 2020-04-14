#include "drink_machine.h"

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

DrinkMachine::DrinkMachine() {

    inventory[0].name = "Cola";
    inventory[0].price = 0.75;
    inventory[0].qty = 20;

    inventory[1].name = "Root Beer";
    inventory[1].price = 0.75;
    inventory[1].qty = 20;

    inventory[2].name = "Orange Soda";
    inventory[2].price = 0.75;
    inventory[2].qty = 20;

    inventory[3].name = "Grape Soda";
    inventory[3].price = 0.75;
    inventory[3].qty = 20;

    inventory[4].name = "Bottled water";
    inventory[4].price = 1.00;
    inventory[4].qty = 20;

}

void DrinkMachine::display_choices() {
                                                 
    cout << "  Drink Name" << setw(25) <<    "Cost" << setw(25) << "Number in Machine" << endl;
    cout << "****************************************************************" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << (i+1) << ". " << left << setw(22) << inventory[i].name 
                << right << setw(12) << setprecision(2) << fixed << inventory[i].price
                    << setprecision(0) << setw(18) << inventory[i].qty << endl;
    }

    cout << "****************************************************************" << endl;


}

void DrinkMachine::buy_drink(const int& choice, const double& inserted) {
   
    double change;

    change = input_money(choice, inserted);
    
    cout << setprecision(2) << fixed << "-- CHANGE: $" << change << " --\n";

}

double DrinkMachine::input_money(const int& choice, const double& inserted) {

    char confirm;
    
    // Return money if sold out
    if(inventory[choice-1].qty == 0)
    {

        cout << "-- SOLD OUT --\n";
        return inserted;

    }

    // Confirm Purchase
    cout << "You want to purchase a " << inventory[choice-1].name << "(Y/n)? ";
    cin >> confirm;

    if(confirm == 'Y' || confirm == 'y')
    {
        if (inserted < inventory[choice-1].price)
        {
            cout << "-- NOT ENOUGH FUNDS --\n";
            return inserted;
        }

        inventory[choice-1].qty--;
        cout << "-- SODA DELIVERED --\n";
        return (inserted - inventory[choice-1].price);

    }
    else
    {
            // Return money if not confirmed
            return inserted;
    }
}

void DrinkMachine::daily_report() {
    
    system("clear");
    double total = 0;

    for (int i = 0; i < 5; i++)
    {
        cout << inventory[i].name << ": " << inventory[i].qty << " remaining\n";
        total += (20 - inventory[i].qty) * inventory[i].price;
    }

    cout << "Money collected: $" << total << endl << endl;
}