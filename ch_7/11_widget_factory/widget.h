#ifndef WIDGET_H
#define WIDGET_H

class Widget
{
private:
    int widgetPerHour;
    int numOfShifts;
    int hoursPerShift;
    int numToOrder;

public:
    Widget();
    Widget(int wph, int nos, int hps);
    void set_order_number(int &order);
    int get_days_to_make();

};

#endif