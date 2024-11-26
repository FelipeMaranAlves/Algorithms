#include <iostream>
#include <fstream>
using namespace std;

class Date
{
private:
    /* data */
public:
    Date(/* args */);
    ~Date();

    void init( int month, int day, int year);
    void init(void);
    void print(void);

};



int main(){
    ifstream fin("input");
    ofstream fout("output");
    
    return 0;
}