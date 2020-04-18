#include <iostream>
#include "Numbers.h"

using namespace std;

int main() {

    int input;

    cout << "Enter number 0-9999: ";
    cin >> input;

    Numbers *ptr = new Numbers(input);
    
    cout << endl;
    ptr->print();
    cout << endl << endl;

    delete ptr;

    return 0;
}