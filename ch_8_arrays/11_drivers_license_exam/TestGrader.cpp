#include "TestGrader.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define DEFAULT_ANS "BDAACABACDBCDADCCBDA"

TestGrader::TestGrader(){
    set_key(DEFAULT_ANS);
}

void TestGrader::set_key(const string& s){
    if(s.length() != 20)
    {
        cout << "Error. Invalid number of answers.";
        return;
    }

    for(int i = 0; i < s.length(); i++){
        if(s[i] != 'A' && s[i] != 'B' && s[i] != 'C' && s[i] != 'D')
        {
            cout << "Error. Invalid character in key";
            return;
        }
    }

    for(int i = 0; i < s.length(); i++)
        this->answers[i] = s[i];
}

void TestGrader::grade(const char s[]){
    vector<int> incorrect;

    for(int i = 0; i < 20; i++)
    {
        if(s[i] != answers[i])
            incorrect.push_back(i);
    }

    if(incorrect.size() < 6)
        cout << "PASSED\n";
    else
        cout << "FAILED\n";

    cout << "Number Correct: " << 20 - incorrect.size() << endl;
    cout << "Number Incorrect: " << incorrect.size() << endl;
    cout << "Missed Questions: ";

    for(int i =0; i < incorrect.size(); i++)
        cout << incorrect[i] << " ";
    
    cout << endl;
}