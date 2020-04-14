#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define NUM_MONTHS 12
int month;
const string MONTH_NAMES[] {"January", "February", "March", "April", "May", "June",
                     "July", "August", "September", "October", "November", "December"};

void get_data(double[]);
double total_rainfall(const double[]);
double average_rainfall(const double[]);
int driest_month(const double[]);
int wettest_month(const double[]);
void display_report(int year, string location, const double data[]);

int main()
{
    string location;
    int year;
    double precipitationData[NUM_MONTHS];

    cout << "Enter year: ";
    cin >> year;
    cout << "Enter Location: ";
    cin >> location;

    get_data(precipitationData);
    system("clear");
    display_report(year, location, precipitationData);

    cout << endl;

    return 0;
}

void get_data(double data[])
{
    ifstream inputFile;
    inputFile.open("CincinnatiRainfall2019.dat");

    for(month = 0; month < NUM_MONTHS; month++)
    {
        inputFile >> data[month];
       /* do
        {
            cout << "Enter rainfall for " << MONTH_NAMES[month] << ": ";
            cin >> data[month];

            if(data[month] < 0)
                cout << "Error: Enter positive number.\n";

        } while (data[month] < 0); */  
    }

    inputFile.close();
}

double total_rainfall(const double data[])
{
    double total = 0;

    for(month = 0; month < NUM_MONTHS; month++)
        total += data[month];

    return total;
}

double average_rainfall(const double data[])
{
    double total = total_rainfall(data);
    return total / NUM_MONTHS;
}

int driest_month(const double data[])
{
    int driest = 0;

    for(month = 1; month < NUM_MONTHS; month++)
        driest = (data[driest] > data[month]) ? month : driest;

    return driest;
}

int wettest_month(const double data[])
{
    int wettest = 0;

    for(month = 1; month < NUM_MONTHS; month++)
        wettest = (data[wettest] < data[month]) ? month : wettest;

    return wettest;
}

void display_report(int year, string location, const double data[])
{
    int driest = driest_month(data),
        wettest = wettest_month(data);

    cout << "     " << year << " Rain Report for " << location << endl;
    cout << endl;
    cout << "Total rainfall: " << total_rainfall(data) << " inches\n";
    cout << "Average monthly rainfall: " << average_rainfall(data) << " inches\n";
    cout << "The least rain fell in " << MONTH_NAMES[driest] << " with " << data[driest] << " inches.\n";
    cout << "The most rain fell in " << MONTH_NAMES[wettest] << " with " << data[wettest] << " inches.\n";
}