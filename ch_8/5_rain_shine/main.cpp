#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#define NUM_MONTHS 3
#define NUM_DAYS 30
#define NUM_CONDITIONS 3

int month = 0, 
      day = 0,
      cond = 0;

string monthNames[] {"June", "July", "August", "Summer"};
string condNames[] {"Rainy", "Cloudy", "Sunny"};

void initialize_report_array(int[][NUM_MONTHS+1]);
void fill_report_with_weather(const char[][NUM_DAYS], int[][NUM_MONTHS+1]);
int get_most_rain(const int[][NUM_MONTHS+1]);
void print_report(const int[][NUM_MONTHS+1], int);

int main()
{
    // Open data file
    ifstream inputFile;
    inputFile.open("RainOrShine.dat");

    if(!inputFile) // If file doesn't open
    {
        cout << "Error opening file!";
    }
    else // If file opens
    {
        char weather[NUM_MONTHS][NUM_DAYS];
        int report[NUM_CONDITIONS][NUM_MONTHS+1];

        initialize_report_array(report);

        for(month = 0; month < NUM_MONTHS; month++)
        {
            for(day = 0; day < NUM_DAYS; day++)
                inputFile >> weather[month][day]; // Read file data to array
        }

        inputFile.close(); // Close file


        // BEGIN REPORT
        fill_report_with_weather(weather, report);
        print_report(report, get_most_rain(report));
        
    }
    
    cout << "\n";

    return 0;
}

void initialize_report_array(int data[][NUM_MONTHS+1])
{
    for(cond = 0; cond < NUM_CONDITIONS; cond++)
    {
        for(month = 0; month < NUM_MONTHS+1; month++)
            data[cond][month] = 0;
    }
}

void fill_report_with_weather(const char weather[][NUM_DAYS], int report[][NUM_MONTHS+1])
{
    // Calculate conditions for each month
    for(month = 0; month < NUM_MONTHS; month++)
    {
        for(day = 0; day < NUM_DAYS; day++)
        {

            if(weather[month][day] == 'R')
                report[0][month]++;
            else if(weather[month][day] == 'C')
                report[1][month]++;
            else if(weather[month][day] == 'S')
                report[2][month]++;
            else
                cout << "Error with data!\n";           
    
        }
    }

    // Calculate summer total for each condition
    for(cond = 0; cond < NUM_CONDITIONS; cond++)
    {
        for(month = 0; month < NUM_MONTHS; month++)
            report[cond][NUM_MONTHS] += report[cond][month];
    }
}

int get_most_rain(const int data[][NUM_MONTHS+1])
{
    int highestMonth = 0;

    for(month = 1; month < NUM_MONTHS; month++)
        highestMonth = (data[0][highestMonth] < data[0][month]) ? month : highestMonth;

    return highestMonth;
}

void print_report(const int data[][NUM_MONTHS+1], int highest)
{
    cout << "       ";
    for(month = 0; month < NUM_MONTHS+1; month++) // Print month names header
        cout << monthNames[month] << "   ";

    cout << endl;

    for(cond = 0; cond < NUM_CONDITIONS; cond++)
    {
        cout << condNames[cond] << "    ";

        for(month = 0; month < NUM_MONTHS+1; month++)
            cout << data[cond][month] << "      ";

        cout << endl;
    }

    cout << "Rainiest Month: " << monthNames[highest];
}