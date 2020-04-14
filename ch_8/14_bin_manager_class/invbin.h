#ifndef INV_BIN_H
#define INV_BIN_H

#include <string>
using namespace std;

class InvBin {

    private:

        string description;
        int qty;

    public:

        InvBin(string d = "empty", int q = 0) 
        {   description = d; qty = q;   }

        void set_description(string d)
        {   description = d;    }
        string get_description()
        {   return description; }
        void set_qty(int q)
        {   qty = q;    }
        int get_qty()
        {   return qty;    }

};

#endif