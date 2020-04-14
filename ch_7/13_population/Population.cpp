#include "Population.h"



Population::Population(int cp, int ab, int ad)
{
    cp = (cp < 2) ? 2 : cp;
    ab = (ab < 0) ? 0 : ab;
    ad = (ad < 0) ? 0 : ad;
    this->currentPopulation = cp;
    this->annualBirths = ab;
    this->annualDeaths = ad;
}

void Population::set_population(int cp)
{
    cp = (cp < 2) ? 2 : cp;
    this->currentPopulation = cp;
}
    
void Population::set_births(int ab)
{
    ab = (ab < 0) ? 0 : ab;
    this->annualBirths = ab;
}

void Population::set_deaths(int ad)
{
    ad = (ad < 0) ? 0 : ad;
    this->annualDeaths = ad;
}

double Population::get_birth_rate()
{
    return (double) annualBirths / currentPopulation;
}
    
double Population::get_death_rate()
{
    return (double) annualDeaths / currentPopulation;
}