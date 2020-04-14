#include "PatientAccount.h"

PatientAccount::PatientAccount(const double & dailyRate)
{
    this->dailyRate = dailyRate;
    this->daysInHospital = 1;
    this->totalCharges = 0;
}

PatientAccount::PatientAccount(const double& dailyRate, const double& appendectomyPrice, const double& cataractPrice, 
            const double& hysterectomyPrice, const double& mastectomyPrice, 
            const double& tonsillectomyPrice)
{
    this->dailyRate = dailyRate;
    this->daysInHospital = 1;
    this->totalCharges = 0;
    this->surg.set_appendectomy_price(appendectomyPrice);
    this->surg.set_cataract_price(cataractPrice);
    this->surg.set_hysterectomy_price(hysterectomyPrice);
    this->surg.set_mastectomy_price(mastectomyPrice);
    this->surg.set_tonsillectomy_price(tonsillectomyPrice);
}