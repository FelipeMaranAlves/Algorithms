#include <iostream>
#include <fstream>
using namespace std;


int test[999];
int const tsize = 999;
int primes[tsize/2];
int psize = 0;

bool isPrime(int number) {
    
    for (int i = 0; i < psize; i++)
    {
        if (number % primes[i] == 0) {return false;}
    }

    return true;
}

int main(){
    ifstream fin("input");
    ofstream fout("output");
    for (int i = 0; i < tsize; i++)
    {
        test[i] = i+2;
    }
    fout << test[0] << " " << test[98] << endl;


    for (int i = 0; i < tsize; i++)
    {
        if (isPrime(test[i])) {
            primes[psize] = test[i];
            psize++;
        }
    }
    

    for (int i = 0; i < psize; i++)
    {
        fout << primes[i] << " ";
    }
    fout << endl << psize;
    return 0;
}