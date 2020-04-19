#include "EncryptableString.h"


// Additional members
void EncryptableString::encrypt() {

    for (char& letter : message)
    {
        if ( letter == 'z' )
            letter = 'a';

        else if ( letter == 'Z' )
            letter = 'A';

        else
            letter++;
    }

}

// Overloads
void EncryptableString::operator= (const string& input) {

    this->message = input;
}

istream &operator>>(istream& in, EncryptableString& input) {

    string temp;
    in >> temp;
    input.message = temp;

    return in;

}

ostream &operator<<(ostream& out, EncryptableString& output) {

    out << output.message;
    return out;
}