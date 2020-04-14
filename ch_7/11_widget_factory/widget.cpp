#include "widget.h"

Widget::Widget()
{
    this->numOfShifts = 2;
    this->hoursPerShift = 8;
    this->widgetPerHour = 10;
    this->numToOrder = 0;
}

Widget::Widget(int wph, int nos, int hps)
{
    this->widgetPerHour = wph;
    this->numOfShifts = nos;
    this->hoursPerShift = hps;
    this->numToOrder = 0;
}

void Widget::set_order_number(int &order)
{ 
    if (order < 0)
        order = 0;

    this->numToOrder = order;
}

int Widget::get_days_to_make()
{
    return (numToOrder / 10) / (numOfShifts * hoursPerShift);
}