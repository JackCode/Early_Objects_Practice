#ifndef P_STRING_H
#define P_STRING_H

#include <string>
#include <iostream>
using namespace std;

class Pstring : public string {
    
    private:

        string input;

    public:

        // Constructor
        Pstring(){};
        Pstring(string input) : string(input), input(input) {}; 

        // Additional members
        bool isPalindrome();
        void set_string(string input);

        // Overload
        friend istream & operator >> (istream &in,  Pstring &str); 
};

#endif