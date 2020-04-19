#ifndef DIV_SALES_H
#define DIV_SALES_H

#define NUM_PERIODS 4

class DivSales {

    private:
        // Static Members
        static double regionSales;

        // Instance Members
        double quarterlySales[NUM_PERIODS];

    public:
        // Constructor
        DivSales();
        DivSales(const double &q1, const double &q2, const double &q3, const double &q4);

        // Setters
        void set_quarterly_sales(const double &q1, const double &q2, const double &q3, const double &q4);

        // Getters
        double get_specified_qtr_sales(const int &qtr);
        double get_region_sales()
            { return regionSales; }

};


#endif