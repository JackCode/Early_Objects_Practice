#include <iostream>
#include <string>
#include "Heading.h"

using namespace std;

int main() 
{

    string comp = "Pet Pals", 
            rep = "Payroll Report";
    Heading reportHeading(comp, rep);

    reportHeading.print_one_line();
    cout << "\n";
    reportHeading.print_box_report();
    cout << "\n";

    return 0;
}