//**********************************************//
// This program utilizes a simple linear search //
// to determine if winning lottery numbers      //
// match any of the user's tickets              //
//**********************************************//

#include <iostream>

#define NUM_TIX 10

using namespace std;

int main() {

    int winningNumbers;
    int tickets[] { 13579, 26791, 26792, 33445, 55555,
                    62483, 77777, 79422, 85647, 93121 };

    cout << "Winning Numbers: ";
    cin >> winningNumbers;

    for ( int i = 0; i < NUM_TIX; i++ )
    {

        if ( winningNumbers == tickets[i])
        {

            cout << "\nWINNER!\n\n";
            return 0;

        }

    }

    cout << "\n Sorry, not a winner.\n\n";

    return 0;

}