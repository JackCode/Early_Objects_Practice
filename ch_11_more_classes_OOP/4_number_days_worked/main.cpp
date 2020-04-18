#include <iostream>

#include "NumDays.h"

using namespace std;

int main() {

    NumDays weber_jerod(36), mcalpine_aaron(52);

    cout << "Jerod\n";
    cout << "Hours worked: " << weber_jerod.get_hours_worked() << endl;
    cout << "Days worked:  " << weber_jerod.get_days_worked() << endl << endl;

    cout << "Aaron\n";
    cout << "Hours worked: " << mcalpine_aaron.get_hours_worked() << endl;
    cout << "Days worked:  " << mcalpine_aaron.get_days_worked() << endl << endl;

    cout << "Together, Jerod and Aaron worked " << weber_jerod + mcalpine_aaron << " hours.\n";
    cout << "Aaron worked " << mcalpine_aaron - weber_jerod << " more hours that Jerod.\n\n";

    cout << "Adding an hour to Jerod\'s time...\n";
    weber_jerod++;

    cout << "Subtracting an hour from Aaron\'s time...\n";
    mcalpine_aaron--;

    cout << "\n";

    cout << "Now, Aaron has worked " << mcalpine_aaron - weber_jerod << " more hours than Jerod.\n\n";

    return 0;
}