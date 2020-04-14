//**********************************************//
// This program utilizes a binary search        //
// to determine if winning lottery numbers      //
// match any of the user's tickets              //
//**********************************************//

#include <iostream>

#define NUM_TIX 10

using namespace std;

void sort_array(int[]);
bool binarySearch(int[], int, int);

int main() {

    int winningNumbers;
    int tickets[] { 13579, 26791, 26792, 33445, 55555,
                    62483, 77777, 79422, 85647, 93121 };

    cout << "Winning Numbers: ";
    cin >> winningNumbers;

    for ( int i = 0; i < NUM_TIX; i++ )
    {

        if ( binarySearch(tickets, NUM_TIX, winningNumbers) )
        {

            cout << "\nWINNER!\n\n";
            return 0;

        }

    }

    cout << "\nSorry, not a winner.\n\n";

    return 0;

}

void sort_array(int arr[]) {

    int tempEntry;
    bool swap;

    do 
    {
        swap = false;

        for ( int i = 0; i < (NUM_TIX-1); i++ ) // Run through, carry largest to right
        {

            if ( arr[i] > arr[i+1] )        // If left is bigger than right, switch positions
            {

                tempEntry = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tempEntry;

            }

            swap = true;

        }

    } while (swap);

}

bool binarySearch(int arr[], int size, int value) {

    int first = 0,
        last = size -1,
        middle;

    while ( first <= last )
    {

        middle = (first + last) / 2;

        if ( arr[middle] == value )
        {

            return true;

        }
        else if ( arr[middle] > value )
        {

            last = middle - 1;           

        }
        else
        {
            
            first = middle + 1;

        }

    }

    return false;

}