#include <iostream>
#include "rainfall.h"
#include <ctime>
using namespace std;


int main() {


    // The main program currently provides proof of concept of class
    // TODO: Create a command line menu driven interface

    Rainfall year2019;
    srand(time(0));

    for ( int rainfall = 2; rainfall < 14; rainfall++ )
        year2019.set_rain(rainfall-1, rand() % 10);

    system("clear");
    year2019.sort_by_rain();
    year2019.display_data();
    cout << "\n";
    year2019.sort_chrono();
    year2019.display_data();
    cout << "\n";
    year2019.sort_alpha();
    year2019.display_data();
    cout << "\n\n";
    return 0;

}