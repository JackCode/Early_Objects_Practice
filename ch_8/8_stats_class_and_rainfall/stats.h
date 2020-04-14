#ifndef STATS_H
#define STATS_H

class Stats
{
private:
    double data[30];
    int numData;

public:
    Stats();
    double total();
    double average();
    int highest();
    int lowest();
    bool store_value(const double&);
    double get_data(const int&);

};

#endif