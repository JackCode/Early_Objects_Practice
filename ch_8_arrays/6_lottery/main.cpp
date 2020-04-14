#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));

    int winning[5];
    int player[5];
    int i;
    int matchingDigits = 0;

    for(i = 0; i < 5; i++)          // Retrieve Player's Numbers
    {
        do
        {
            cout << "Enter Number: ";
            cin >> player[i];

            if(player[i] < 0 || player[i] > 9)
                cout << "Invalid Entry. Enter a number 0-9.\n";

        } while (player[i] < 0 || player[i] > 9); 
    }

    for(i = 0; i < 5; i++)          // Generate Winning Numbers
        winning[i] = rand() % 10;

    for(i = 0; i < 5; i++)          // Compare Numbers
    {
        if(player[i] == winning[i])
            matchingDigits++;
    }

    system("clear");
    cout << "Winning Numbers:  ";
    for(i = 0; i < 5; i++)          //Display Winning Numbers
        cout << winning[i] << " ";
    cout << endl;

    cout << "Player's Numbers: ";
    for(i = 0; i < 5; i++)          //Display Player Numbers
        cout << player[i] << " ";
    cout << endl << endl;

    cout << "You matched " << matchingDigits << " numbers correctly!\n\n";

    return 0;
}