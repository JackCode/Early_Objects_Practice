#include "stats.h"

#include <iostream>
using namespace std;

Stats::Stats()
{
    this->numData = 0;
}

double Stats::total()
{
    double total = 0;

    for(int i = 0; i < numData; i++)
    {
        total += this->data[i];
    }
        

    return total;
}

double Stats::average()
{
    return this->total() / this->numData;
}

int Stats::highest()
{
    int highest = 0;

    if(this->numData == 0)
        return -1;          // Returns -1 if no data is stored
    else
    {
        for(int i = 1; i < numData; i++)
            highest = (this->data[highest] < this->data[i]) ? i : highest;
    }

    return highest;
}

int Stats::lowest()
{
    int lowest = 0;

    if(this->numData == 0)
        return -1;          // Returns -1 if no data is stored
    else
    {
        for(int i = 1; i < numData; i++)
            lowest = (data[lowest] > data[i]) ? i : lowest;
    }

    return lowest;
}

double Stats::get_data(const int& location)
{
    return data[location];
}

bool Stats::store_value(const double& input)
{
    if(numData < 30)
    {
        this->data[numData] = input;
        (this->numData)++;
        return true;
    }
    else
        return false;
}