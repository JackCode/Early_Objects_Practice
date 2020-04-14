#include <iostream>

#include "Population.h"

using namespace std;

int main()
{

    Population clermont(203216, 4000, 3005);

    cout << "Birth rate: " << clermont.get_birth_rate() << endl;
    cout << "Death rate: " << clermont.get_death_rate() << endl;

    return 0;
}