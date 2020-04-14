#include <iostream>
#include <fstream>
#include "stats.h"
using namespace std;

void get_data(Stats&, ifstream&);
void print_report(Stats&);

const string MONTH_NAMES[] {"January", "February", "March", "April", "May", "June",
                     "July", "August", "September", "October", "November", "December"};

int main()
{

    Stats rain;
    ifstream inputFile;
    inputFile.open("CincinnatiRainfall2019.dat");

    if(inputFile)
    {
        get_data(rain, inputFile);
        system("clear");
        print_report(rain);
        cout << "\n";

        inputFile.close();
    }
    else
    {
        cout << "Error opening file\n";
    }

    return 0;
}


void get_data(Stats& s, ifstream& file)
{
    double data;

    while(file >> data)
    {
        if(s.store_value(data)){}
        else
        {
            cout << "Error storing data.\n";
            return;
        }   
    }
}

void print_report(Stats& s)
{
    cout << "     2019 Rain Report for Cincinnati, OH" << endl;
    cout << endl;
    cout << "Total rainfall: " << s.total() << " inches\n";
    cout << "Average monthly rainfall: " << s.average() << " inches\n";
    cout << "The least rain fell in " << MONTH_NAMES[s.lowest()] << " with " << s.get_data(s.lowest()) << " inches.\n";
    cout << "The most rain fell in " << MONTH_NAMES[s.highest()] << " with " << s.get_data(s.highest()) << " inches\n";
}