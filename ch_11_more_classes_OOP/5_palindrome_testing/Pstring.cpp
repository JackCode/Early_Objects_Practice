#include "Pstring.h"
#include <cctype>

bool Pstring::isPalindrome() {

    int strLength = input.length();
    int back = strLength - 1;

    for (int index = 0; index <= (strLength / 2); index++, back--)
    {
        if (tolower(input[index]) != tolower(input[back]))
            return false;
    }

    return true;

}

void Pstring::set_string(string input) {

    this->input = input;

}

istream & operator >> (istream &in,  Pstring &str) { 
    string temp;

     in >> temp;
     str.set_string(temp);

     return in;
} 