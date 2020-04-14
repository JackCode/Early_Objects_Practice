#include "binmanager.h"

BinManager::BinManager(int size, string d[], int q[])
{
    numBins = size;

    for ( int i = 0 ; i < size ; i++ )
    {
        bin[i].set_description(d[i]);
        bin[i].set_qty(q[i]);
    }
}

string BinManager::get_description(int index)
{
    return bin[index].get_description();
}

int BinManager::get_quantity(int index)
{
    return bin[index].get_qty();
}

string BinManager::display_all_bins()
{
    string list = "";

    for ( int i = 0 ; i < numBins ; i++)
        list += (bin[i].get_description() + "\n");

    return list;
}

bool BinManager::add_parts(int binIndex, int q)
{
    if( q < 1 )
    {
        return false;
    }
    
    bin[binIndex].set_qty(bin[binIndex].get_qty() + q);
    return true;

}

bool BinManager::remove_parts(int binIndex, int q)
{
    if( q < 1 || q > bin[binIndex].get_qty())
    {
        return false;
    }
    
    bin[binIndex].set_qty(bin[binIndex].get_qty() - q);
    return true;
}