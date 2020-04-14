#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;

class Car
{
private:
    string make;
    int year;
    int speed;

public:
    Car(int, string);
    int get_year();
    int get_speed();
    string get_make();
    void accelerate(){this->speed+=5;}
    void brake(){this->speed-=5;}

};

#endif