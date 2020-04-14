#include "payroll.h"

void PayRoll::set_worker_info(double rate, double hours) {
    this->hourlyRate = rate;
    this->hoursWorked = hours;
}

double PayRoll::get_gross_pay() {
    return hoursWorked * hourlyRate;
}