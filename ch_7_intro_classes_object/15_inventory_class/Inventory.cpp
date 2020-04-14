#include "Inventory.h"

Inventory::Inventory()
{
    cost = 0;
    quantity = 0;
    itemNumber = 0;
    totalCost = 0;
}
    
Inventory::Inventory(const int & itemNumber, const int & quantity, const double & cost)
{
    this->setCost(itemNumber);
    this->setItemNumber(quantity);
    this->setQuantity(cost);

    this->setTotalCost();
}

void Inventory::setItemNumber(int itemNumber)
{
    itemNumber = (itemNumber < 0) ? 0 : itemNumber;
    this->itemNumber = itemNumber;
}

void Inventory::setQuantity(int quantity)
{
    quantity = (quantity < 0) ? 0 : quantity;
    this->quantity = quantity;
}

void Inventory::setCost(double cost)
{
    cost = (cost < 0) ? 0 : cost;
    this->cost = cost;
}

void Inventory::setTotalCost()
{
    totalCost = quantity * cost;
}