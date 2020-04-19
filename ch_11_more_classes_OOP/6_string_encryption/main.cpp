#include <iostream>
#include "EncryptableString.h"
using namespace std;

int main () {

    EncryptableString str;

    while (true) 
    {
        cout << "Enter string: ";
        cin >> str;
        str.encrypt();
        cout << "Encrypted message: " << str << endl << endl;     


    }

    return 0;
}