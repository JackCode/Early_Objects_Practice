#ifndef POPULATION_H
#define POPULATION_H


class Population
{
private:
    int currentPopulation;
    int annualBirths;
    int annualDeaths;

public:
    Population(int cp, int ab, int ad);
    void set_population(int);
    void set_births(int);
    void set_deaths(int);
    double get_birth_rate();
    double get_death_rate();

};


#endif