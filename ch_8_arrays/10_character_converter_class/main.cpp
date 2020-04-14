#include <iostream>
#include <string>
#include "CharConverter.h"
using namespace std;

int main()
{
    CharConverter conv;
    string sentence;

    while(true)
    {
        cout << "Sentence (CTRL + c to quit): ";
        getline(cin, sentence);
        
        cout << conv.uppercase(sentence) << endl;
        cout << conv.proper_words(sentence) << endl;
    }

    return 0;
}