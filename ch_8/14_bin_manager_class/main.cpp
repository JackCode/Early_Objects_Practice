#include <iostream>
#include <string>
#include "binmanager.h"

#define NUM_PARTS 9
#define PARTS_LIST {"Regular pliers", "N. nose pliers", "screwdriver", "P. head screw driveer",\
                    "Wrench-large", "Wrench-small", "Drill", "Cordless drill", "Hand saw"}
#define PARTS_QTY {25, 5, 25, 6, 7, 18, 51, 16, 12}

using namespace std;



int main() {

    string parts[] PARTS_LIST;
    int qty[] PARTS_QTY;

    BinManager warehouse(NUM_PARTS, parts, qty);

    cout << warehouse.display_all_bins();

    return 0;
}