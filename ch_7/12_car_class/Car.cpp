#include <string>
#include "Car.h"
using namespace std;

Car::Car(int year, string make)
{
    this->year = year;
    this->make = make;
    this->speed = 0;
}

int Car::get_speed()
{
    return this->speed;
}

string Car::get_make()
{
    return this->make;
}

int Car::get_year()
{
    return this->year;
}