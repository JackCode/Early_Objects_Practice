#include "Tips.h"

Tips::Tips(double rate = 0.065)
{
    rate = (rate < 0) ? 0.065 : rate;
    this->taxRate = rate;
}

double Tips::compute_tip(double bill, double tipRate)
{
    bill = (bill < 0) ? 0 : bill;
    tipRate = (tipRate < 0) ? 0 : tipRate;

    return (bill / (1 + this->taxRate)) * tipRate;
}