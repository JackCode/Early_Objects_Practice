#include <iostream>
#include <string>
#include "TestGrader.h"
using namespace std;

int main() {

    string ans;
    char ansChar[20];
    TestGrader test;

    while(true)
    {
        cout << "Enter answers (CTRL + C to quit): ";
        cin >> ans;

        for(int i = 0; i < 20; i++)
            ansChar[i] = ans[i];
        test.grade(ansChar);
        cout << "\n";
    }

    return 0;
}