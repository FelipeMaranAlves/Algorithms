#include <iostream>
#include <time.h> // Prototype of time()
#include <stdlib.h> // Prototypes of srand() and rand()
using namespace std;

int main(){
    long long sec;
    time(&sec); // Take the number of seconds and
    srand((unsigned) sec); // use it to initialise.
    bool controle2 = true;
    bool controle1 = true;
    int entrada, resposta;
    int errocount = 0;
   while (controle1)
   {
     while (controle2)
    {
        resposta = rand();
        if (0 < resposta && resposta < 16)
        {
            controle2 = false;
        }
    }
    
    cin >> entrada;

    if (entrada == resposta)
    {
        cout << "yay";
    } else if (entrada == -1){
        controle1 = false;
        cout << "fim";
    } else {
        cout << "errou";
        errocount++;
    }
   }
   
    
    return 0;
}


