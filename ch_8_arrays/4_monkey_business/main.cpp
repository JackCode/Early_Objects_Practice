#include <iostream>
#include <string>
using namespace std;

#define NUM_MONKEYS 3
#define NUM_DAYS 7

double get_avg_food(const double[][NUM_DAYS]);
double get_least(const double[][NUM_DAYS]);
double get_greatest(const double[][NUM_DAYS]);
int monkey, day;

int main()
{
    
    double monkeyFood[NUM_MONKEYS][NUM_DAYS];
    string days[NUM_DAYS] {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    for(monkey = 0; monkey < NUM_MONKEYS; monkey++)
    {
        cout << "Monkey #" << (monkey+1) << " Food Entry\n";

        for(day = 0; day < NUM_DAYS; day++)
        {
            do
            {
                cout << days[day] << ": ";
                cin >> monkeyFood[monkey][day];

                if(monkeyFood[monkey][day] < 0)
                    cout << "Invalid Entry. Enter positive number.\n";

            } while (monkeyFood[monkey][day] < 0); 
        }
        
        system("clear");
    }

    cout << "Average food per monkey: " << get_avg_food(monkeyFood) << endl;
    cout << "Least food eaten during week: " << get_least(monkeyFood) << endl;
    cout << "Most food eaten during week: " << get_greatest(monkeyFood) << endl; 

    return 0;
}

double get_avg_food(const double data[][NUM_DAYS])
{
    double totalFood = 0;

    for(monkey = 0; monkey < NUM_MONKEYS; monkey++)
    {
        for(day = 0; day < NUM_DAYS; day++)
           totalFood += data[monkey][day]; 
    }

    return totalFood / (NUM_MONKEYS * NUM_DAYS);
}

double get_least(const double data[][NUM_DAYS])
{
    double weektotal = 0, least;

    for(day = 0; day < NUM_DAYS; day++)
        least += data[0][day];

    for(monkey = 2; monkey < NUM_MONKEYS; monkey++)
    {
        weektotal = 0;

        for(day = 0; day < NUM_DAYS; day++)
           weektotal += data[monkey][day]; 

        least = (weektotal < least) ? weektotal : least;
    }

    return least;
}

double get_greatest(const double data[][NUM_DAYS])
{
    double weektotal = 0, most;

    for(day = 0; day < NUM_DAYS; day++)
        most += data[0][day];

    for(monkey = 2; monkey < NUM_MONKEYS; monkey++)
    {
        weektotal = 0;

        for(day = 0; day < NUM_DAYS; day++)
           weektotal += data[monkey][day]; 

        most = (weektotal > most) ? weektotal : most;
    }

    return most;
}