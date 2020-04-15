#ifndef RAINFALL_H
#define RAINFALL_H

#include <string>
using namespace std;

class Rainfall {

    private:

        struct month
        {
            string name;
            double rain;
        };
        
        month data[13];

    public:
        Rainfall();
        void set_rain(int month, double rain);
        void sort_chrono();
        void sort_by_rain();
        void sort_alpha();
        void display_data();
        
    
};

#endif