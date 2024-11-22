#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double a =  0.123456;
    double b = 23.987;
    double c = -123.456;
    cout << left << setw(15) << a << endl;
    cout << setw(12) << right << fixed << setprecision(2) << b << endl;
    cout << scientific << setprecision(4) << c << endl;
    return 0;
}