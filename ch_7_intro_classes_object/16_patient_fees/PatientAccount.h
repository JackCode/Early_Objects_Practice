#ifndef PATIENT_ACCOUNT_H
#define PATIENT_ACCOUNT_H

#include "Surgery.h"
#include "Pharmacy.h"

class PatientAccount
{
private:
    int daysInHospital;
    double dailyRate;
    double totalCharges;
    Surgery surg;
    Pharmacy pharm;

public:
    PatientAccount(const double& dailyRate);
    PatientAccount(const double& dailyRate, const double& appendectomyPrice, const double& cataractPrice, 
            const double& hysterectomyPrice, const double& mastectomyPrice, 
            const double& tonsillectomyPrice);
    
    void add_day_to_stay() { this->daysInHospital++; }
    void set_days_in_hospital(int daysInHospital);
    void set_daily_rate(const double & dailyRate) { this->dailyRate = dailyRate; }
    double check_out() { return daysInHospital * dailyRate + totalCharges; }
    void add_cost_to_total(const double& newCost);
    double get_current_rate() { return dailyRate; }
};


#endif