#ifndef DAY_OF_YEAR_H
#define DA_OF_YEAR_H

#include <string>
using namespace std;

class DayOfYear {

    private:

        int day;
        static string months[];
        static int daysPerMonth[];

    public:

        DayOfYear(int day);
        void print();

};


#endif