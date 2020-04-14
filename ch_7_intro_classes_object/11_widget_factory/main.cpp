#include <iostream>

#include "widget.h"

using namespace std;

int main()
{

    Widget myWidget;
    int ordering;


    cout << "How many widgets to order: ";
    cin >> ordering;
    myWidget.set_order_number(ordering);

    cout << "It will take " << myWidget.get_days_to_make() << " days to make " << ordering << " widgets.\n";

    return 0;
}