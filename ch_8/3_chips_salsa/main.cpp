#include <iostream>
#include <string>
using namespace std;

int get_total_quantity(const int[]);
int get_highest(const int[]);
int get_lowest(const int[]);
int i = 0;

int main()
{

    string salsas[] {"Mild", "Medium", "Sweet", "Hot", "Zesty"};
    int purchase[5];

    cout << "Enter Salsa Order\n"
         << "-----------------\n";

    for(i = 0; i < 5; i++)
    {
        do
        {
            cout << salsas[i] << ": ";
            cin >> purchase[i];
            
            if(purchase[i] < 0)
                cout << "Error. Enter non-negative number.\n";

        } while (purchase[i] < 0); 
    }

    system("clear");

    cout << "Salsa Report\n"
         << "---------------\n\n";

    cout << "Total Jars Sold: " << get_total_quantity(purchase) << endl;
    cout << "Most Sold: " << salsas[get_highest(purchase)] << endl;
    cout << "Fewest Sold: " << salsas[get_lowest(purchase)] << endl;
    cout << "\n";
    
    for(i = 0; i < 5; i++)
        cout << salsas[i] << ": " << purchase[i] << endl;

    cout << "\n";

    return 0;
}

int get_total_quantity(const int s[])
{
    int total = 0;

    for(i = 0; i < 5; i++)
        total += s[i];

    return total;
}

int get_highest(const int s[])
{
    int highest = 0;

    for(i = 1; i < 5; i++)
        highest = (s[i] > s[highest]) ? i : highest;

    return highest;
}

int get_lowest(const int s[])
{
    int lowest = 0;

    for(i = 1; i < 5; i++)
        lowest = (s[i] < s[lowest]) ? i : lowest;

    return lowest;
}