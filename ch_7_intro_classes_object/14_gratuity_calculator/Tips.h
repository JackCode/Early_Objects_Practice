#ifndef TIPS_H
#define TIPS_H

class Tips
{
private:
    double taxRate;

public:
    Tips(double rate);
    double compute_tip(double bill, double tipRate);
};

#endif