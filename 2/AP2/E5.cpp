#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    int entrada, temp;
    int saidas = 0;
    cin >> entrada;
    srand(entrada);
    while (saidas < 20)
    {
        temp = rand();
        if ( 0 < temp && temp < 100)
        {
            cout << temp;
            saidas++;
            cout << endl;
        }       
    }
    return 0;
}