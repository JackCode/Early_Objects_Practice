#include "rainfall.h"
#include <iostream>
#include <string>
using namespace std;

#define MONTHS {"", "January", "February", "March", "April", "May", "June", \
                    "July", "August", "September", "October", "November", "December"}

#define MONTHS_ALPHA {"", "April", "August", "December", "February", "January", "July", "June", \
                          "March", "May", "November", "October", "September" }

Rainfall::Rainfall() {

    string monthNames[] MONTHS;
    
    for ( int i = 0; i < 13; i++ )
    {
        data[i].name = monthNames[i];
        data[i].rain = 0;
    }
        

}

void Rainfall::set_rain(int month, double rain) {

    sort_chrono();

    if ( month < 1 || month > 12)
        cout << "Invalid month.\n";

    else if ( rain < 0 )
        cout << "Invalid rainfall.\n";
    
    else
        data[month].rain = rain;
            
}

void Rainfall::sort_chrono() {

    int startScan, minIndex = 0;
    const string monthNames[] MONTHS;

    

    for ( int count = 0; count < 12; count++ )
    {
        minIndex++;

        for ( startScan = (minIndex+1); startScan <= 12; startScan++ )
        {
            if ( data[startScan].name == monthNames[minIndex] )
            {
                data[0].name = data[startScan].name;
                data[0].rain = data[startScan].rain;
                data[startScan].name = data[minIndex].name;
                data[startScan].rain = data[minIndex].rain;
                data[minIndex].name = data[0].name;
                data[minIndex].rain = data[0].rain;
                data[0].name = "";
                data[0].rain = 0;
            }
        }
    }
}

void Rainfall::sort_alpha() {

    int startScan, minIndex = 0;
    const string monthNames[] MONTHS_ALPHA;

    

    for ( int count = 0; count < 12; count++ )
    {
        minIndex++;

        for ( startScan = (minIndex+1); startScan <= 12; startScan++ )
        {
            if ( data[startScan].name == monthNames[minIndex] )
            {
                data[0].name = data[startScan].name;
                data[0].rain = data[startScan].rain;
                data[startScan].name = data[minIndex].name;
                data[startScan].rain = data[minIndex].rain;
                data[minIndex].name = data[0].name;
                data[minIndex].rain = data[0].rain;
                data[0].name = "";
                data[0].rain = 0;
            }
        }
    }


}

void Rainfall::sort_by_rain() {

    bool swap;

    do 
    {
        swap = false;

        for ( int i = 1; i < 12; i++ ) // Run through, carry largest to right
        {
            if ( data[i].rain > data[i+1].rain )        // If left is bigger than right, switch positions
            {
                data[0].name = data[i].name;
                data[0].rain = data[i].rain;
                data[i].name = data[i+1].name;
                data[i].rain = data[i+1].rain;
                data[i+1].name = data[0].name;
                data[i+1].rain = data[0].rain;
                data[0].name = "";
                data[0].rain = 0;
                swap = true;
            }

        }

    } while (swap);
}

void Rainfall::display_data() {

    for( int i = 1; i <= 12; i++ )
        cout << data[i].name << " " << data[i].rain << " inches.\n";

}
