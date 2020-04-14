#include <iostream>
#include <iomanip>
#include "stats.h"

using namespace std;

#define NUM_RUNNERS 15
#define RUNNERS_LIST "Jerod", "Aaron", "Sandra", "Eric", "Brent", "Chad", "Rhonda", "Emily", "Patrick", "Amelia", \
                        "Tessa", "Willow", "Sloane", "Brittany", "Lucy"

void get_data(Stats&);
void print_report(Stats&);
string runners[NUM_RUNNERS] {RUNNERS_LIST};

int main()
{

    Stats times;
    get_data(times);
    system("clear");
    print_report(times);
    cout << "\n";
    return 0;
}

void get_data(Stats& r)
{
    double time;

    for(int i = 0; i < NUM_RUNNERS; i++)
    {
        do
        {
            cout << "Enter " << runners[i] << "'s time: ";
            cin >> time;

            if(!r.store_value(time))
            {
                cout << "Error storing data.\n";
                return;
            }

        } while (time < 0);
    }
    
}

void print_report(Stats& r)
{
    cout << "         Ohio Raptors Track Team" << endl;
    cout << endl;
    cout << "Average 100 yard-dash time: " << r.average() << " seconds\n";
    cout << "Slowest runner: " << left << setw(11) << runners[r.highest()] 
            << right << setw(6) << r.get_data(r.highest()) << "\n";
    cout << "Fastest runner: " << left << setw(11) << runners[r.lowest()] 
            << right << setw(6) << r.get_data(r.lowest()) << "\n";
}