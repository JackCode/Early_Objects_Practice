#ifndef NUMBERS_H
#define NUMBERS_H

#include <string>
using namespace std;

class Numbers {

    private:

        int number;
        static string lessThan20[];
        static string tens[];
        static string hundredsPlace;
        static string thousandsPlace;
        static string negative;

    public:

        Numbers(int number);  // accept int and assign to number variable
        void print();
};

#endif