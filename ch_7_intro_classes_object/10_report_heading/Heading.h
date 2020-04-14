#ifndef HEADING_H
#define HEADING_H

#include <string>
using namespace std;

class Heading {

private:
    string companyName;
    string reportName;

public:
    Heading(){this->companyName = "ABC Indistries", this->reportName = "Report";}
    Heading(string &company, string& report){this->companyName = company, this->reportName = report;}
    void print_one_line();
    void print_box_report();

};

#endif