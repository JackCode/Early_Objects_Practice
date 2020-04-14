#include <iostream>
#include "PatientAccount.h"
#include "Surgery.h"
using namespace std;

int print_menu(const double& currentRate);

int main()
{
    double hospRate;
    int menuChoice;

    cout << "Daily hospital rate: $";
    cin >> hospRate;
    system("clear");

    PatientAccount weber_jerod(hospRate);

    do
    {
        menuChoice = print_menu(weber_jerod.get_current_rate());
        system("clear");

        switch (menuChoice)
        {
            case 1:
                cout << "Enter new rate: $";
                cin >> hospRate;
                weber_jerod.set_daily_rate(hospRate);
                break;
            case 2:
                cout << "Feature coming soon.";
                break;
            case 3:
                cout << "Feature not supported.";
                break;
            case 4:
                break;
            case 5:
                return 0;
                break;
            default:
                cout << "Invalid Entry.";
                break;
        }
        
        cout << "\n\n";
    } while(menuChoice != 4);
    
    system("clear");
    cout << "Patient Final Bill: $" << weber_jerod.check_out() << endl << endl;

    return 0;
}

int print_menu(const double& currentRate) {
    int choice;

    do
    {
        choice = 0;

        cout << "Hospital Charges" << "\n\n";

        cout << "1. Change Rate (current rate: $" << currentRate << ")\n";
        cout << "2. Add Surgery\n";
        cout << "3. Add Medication\n";
        cout << "4. Check Out\n";
        cout << "5. Exit\n";
        cout << "\n";
        cout << "Enter menu choice (1-5): ";
        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)
            return choice;

        system("clear");
    } while (choice < 1 || choice > 5);
    
}