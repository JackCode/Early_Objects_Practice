#include <iostream>
#include <string>
using namespace std;

int main()
{

    int decimal = 0;

    string numerals[21] {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X",
                             "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX"};

    do
    {
        cout << "Enter number 1-20 (0 to exit): ";
        cin >> decimal;

        if(decimal < 0 || decimal > 20)
            cout << "Invalid Entry! Enter a number between 1-20 (or 0 to exit)\n";
        else if(decimal != 0)
        {
            cout << decimal << " --> " << numerals[decimal] << endl;
        }
        
    } while (decimal != 0);
    
    return 0;
}