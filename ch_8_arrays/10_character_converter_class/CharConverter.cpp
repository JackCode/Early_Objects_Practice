#include "CharConverter.h"
#include <string>
#include <cctype>
using namespace std;

string CharConverter::uppercase(string input)
{
    for(int i = 0; i < input.length(); i++)
        input[i] = toupper(input[i]);

    return input;
}

string CharConverter::proper_words(string input)
{
    input[0] = toupper(input[0]);

    for(int i = 1; i < input.length(); i++)
    {
        if(input[i-1] == ' ')
            input[i] = toupper(input[i]);
        else
            input[i] = tolower(input[i]);
    }

    return input;
}