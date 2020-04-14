#include <iostream>
#include "Car.h"
#include <string>
using namespace std;

int main()
{

    int i;
    Car myCar(2018, "Toyota");

    for(i = 0; i < 5; i++)
    {
        myCar.accelerate();
        cout << "Current speed: " << myCar.get_speed() << "\n";
    }

    cout << endl;
    
    for(i = 0; i < 5; i++)
    {
        myCar.brake();
        cout << "Current speed: " << myCar.get_speed() << "\n";
    }

    return 0;
}