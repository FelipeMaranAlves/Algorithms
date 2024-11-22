#include <iostream>
using namespace std;

// int factorial_rec(int){}

// int factorial_loop(int){}

long double factorial_loop(unsigned int a){
    int temp = a;
    for (int i = a; i > 1 ; i--)
    {
        if (temp > 1) {temp *= (i-1);}
    }
    return temp;
}

long double factorial_rec(unsigned int a){
    if (a == 0 || a == 1) {return 1*a;}
    else {return factorial_rec(a-1)*a;}
}

int main(){
    cout << factorial_rec(5) << endl;
    cout << factorial_loop(5) << endl;
    return 0;
}

