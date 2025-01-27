#ifndef LITERAL
#define LITERAL
#include <bits/stdc++.h>
using namespace std;
    class literal
{
private:
    bool isInt = true;
    int intvalue;
    bool boolvalue;
public:
    literal(int a){
        this->intvalue = a;
    }
        literal(string a){
        if (a == "true")
        {
            this->isInt = false;
            this->boolvalue = true;
        }
        else if (a == "false")
        {
            this->isInt = false;
            this->boolvalue = false;
        }
        else {cout << "isso n e um bool" << endl;}
    }
    ~literal();
};
#endif