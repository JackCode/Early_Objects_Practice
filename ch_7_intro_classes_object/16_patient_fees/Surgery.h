#ifndef SURGERY_H
#define SURGERY_H

class Surgery{
private:
    double appendectomyPrice;
    double cataractPrice;
    double hysterectomyPrice;
    double mastectomyPrice;
    double tonsillectomyPrice;

public:
    Surgery();
    
    void set_appendectomy_price(const double & appendectomyPrice) { this->appendectomyPrice = appendectomyPrice; }
    void set_cataract_price(const double & cataractPrice) { this->cataractPrice = cataractPrice; }
    void set_hysterectomy_price(const double & hysterectomyPrice) { this->hysterectomyPrice = hysterectomyPrice; }
    void set_mastectomy_price(const double & mastectomyPrice) { this->mastectomyPrice = mastectomyPrice; }
    void set_tonsillectomy_price(const double & tonsillectomyPrice) { this->tonsillectomyPrice = tonsillectomyPrice; }

    double get_appendectomy_price() { return appendectomyPrice; }
    double get_cataract_price() { return cataractPrice; }
    double get_hysterectomy_price() { return hysterectomyPrice; }
    double get_mastectomy_price() { return mastectomyPrice; }
    double get_tonsillectomy_price() { return tonsillectomyPrice; }
};

#endif