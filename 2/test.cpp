#include <iostream>
#include <fstream>
using namespace std;


int test[] = {2,3,4,5,6,7,8,9,10,11};
int const tsize = 10;
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
        if (isPrime(test[i])) {
            primes[psize] = test[i];
            psize++;
        }
    }
    

    for (int i = 0; i < psize; i++)
    {
        fout << primes[i] << " ";
    }
    
    return 0;
}