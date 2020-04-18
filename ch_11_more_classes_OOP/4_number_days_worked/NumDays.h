#ifndef NUM_DAYS_H
#define NUM_DAYS_H

class NumDays {

    private:

        double hoursWorked;

    public:
        // Constructor
        NumDays(const double& hoursWorked);

        // Setters
        void set_hours_worked(const double& hoursWorked);

        // Getters
        double get_hours_worked();
        double get_days_worked();

        //Overloads
        double operator+ (const NumDays& addend);
        double operator- (const NumDays& subtrahend);
        NumDays operator++ ();
        NumDays operator++ (int);
        NumDays operator-- ();
        NumDays operator-- (int);

};


#endif