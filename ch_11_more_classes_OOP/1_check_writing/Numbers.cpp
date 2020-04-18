#include "Numbers.h"

#include <iostream>

// Static members
string Numbers::lessThan20[]  {"zero", "one", "two", "three", "four",
                                  "five", "six", "seven", "eight", "nine",
                                  "ten", "eleven", "twelve", "thirteen", "fourteen",
                                  "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string Numbers::tens[] {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};                    
string Numbers::hundredsPlace = "hundred";
string Numbers::thousandsPlace = "thousand";
string Numbers::negative = "negative";

// Instance members

Numbers::Numbers (int number) {

    if (number < 0 || number > 9999)
    {
        std::cout << "Invalid entry. Number must be 0-9999.\n";
        this->number = 0;
    }
    else
        this->number = number;
    
}


void Numbers::print() {

    int tempNumber = this->number;

    if (tempNumber == 0)
    {
        cout << lessThan20[tempNumber];
    }
    else
    {
        if(tempNumber >= 1000)
        {
            std::cout << lessThan20[tempNumber / 1000] << " " << thousandsPlace << " ";
            tempNumber -= (tempNumber / 1000) * 1000;
        }

        if(tempNumber >= 100)
        {
            std::cout << lessThan20[tempNumber / 100] << " " << hundredsPlace << " ";
            tempNumber -= (tempNumber / 100) * 100;
        }

        if(tempNumber >= 10)
        {
            std::cout << tens[tempNumber / 10]  << " ";
            tempNumber -= (tempNumber / 10) * 10;
        }

        if(tempNumber > 0)
            std::cout << lessThan20[tempNumber];
    }

}