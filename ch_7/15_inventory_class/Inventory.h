#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory
{
private:
    int itemNumber,
        quantity;
    double cost,
            totalCost;
public:
    Inventory();
    Inventory(const int & itemNumber, const int & quantity, const double & cost);

    void setItemNumber(int itemNumber);
    void setQuantity(int quantity);
    void setCost(double cost);
    void setTotalCost();

    int getItemNumber() { return itemNumber; }
    int getQuantity() { return quantity; }
    double getCost() { return cost; }
    double getTotalCost() { return totalCost; }

};

#endif