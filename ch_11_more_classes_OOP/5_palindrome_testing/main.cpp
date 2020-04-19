#include <iostream>
#include "Pstring.h"
using namespace std;

int main() {

    Pstring name;

    while (true)
    {
        cout << "Enter string to check for palindrome: ";
        cin >> name;
        cout << "Palidrome? ";

        if(name.isPalindrome())
            cout << "yes\n";
        else
            cout << "no\n";

        cout << endl;        

    }
    return 0;
}