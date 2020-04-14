#ifndef PAYROLL_H
#define PAYROLL_H

class PayRoll {
private:
    double hourlyRate;
    double hoursWorked;

public:
    void set_worker_info(double rate, double hours);
    double get_gross_pay();

};

#endif