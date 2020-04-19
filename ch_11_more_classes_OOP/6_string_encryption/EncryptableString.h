#ifndef ENCRYPTABLE_STRING_H
#define ENCRYPTABLE_STRING_H

#include <string>
#include <iostream>
using namespace std;

class EncryptableString : public string {

    private:

        string message;

    public:
        EncryptableString() : string(){};
        EncryptableString(string input) : string(input), message(input){};

        // Additional members
        void encrypt();

        // Overloads
        void operator= (const string& input);
        friend istream &operator>>(istream& in, EncryptableString& input);
        friend ostream &operator<<(ostream& out, EncryptableString& output);


};

#endif