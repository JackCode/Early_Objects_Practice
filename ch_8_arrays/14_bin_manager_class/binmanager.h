#ifndef BIN_MANAGER_H
#define BIN_MANAGER_H

#include "invbin.h"
#include <string>
using namespace std;

class BinManager {

    private:
        InvBin bin[30];
        int numBins;

    public:
        BinManager() { numBins = 0; }

        BinManager(int size, string d[], int q[]);

        string get_description(int index);
        int get_quantity(int index);
        string display_all_bins();

        bool add_parts(int binIndex, int q);
        bool remove_parts(int binIndex, int q);

};

#endif