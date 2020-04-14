#ifndef TEST_GRADER_H
#define TEST_GRADER_H

#include <string>
using namespace std;

class TestGrader{
private:
    char answers[20];

public:
    TestGrader();
    void set_key(const string&);
    void grade(const char[]);
};

#endif