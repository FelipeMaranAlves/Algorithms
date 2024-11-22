#include <iostream>
using namespace std;
#define ABS(a) (a > 0 ? a : -a)
#define MAX(a, b) (a > b ? a : b)

int main(){
    cout << ABS(5) << " " << ABS(-6) << endl;
    cout << MAX(2,-1) << endl;
    cout << MAX(-1,3) << endl;
    return 0;
}