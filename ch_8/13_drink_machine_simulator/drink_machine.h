#ifndef DRINK_MACHINE_H
#define DRINK_MACHINE_H

#include <string>

class DrinkMachine {
    
    private:

        struct soda {

            std::string name;
            double price;
            int qty;

        };

        soda inventory[5];
        double input_money(const int& choice, const double& inserted);
        void daily_report();

    public:

        DrinkMachine();
        ~DrinkMachine() { daily_report(); }
        void display_choices();
        void buy_drink(const int& choice, const double& inserted);

};


#endif