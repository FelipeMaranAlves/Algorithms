#include <iostream>
#define BANANA(str) (str.size()%2 == 0 ? (str.size()/2) : (str.size()/2)+1)
using namespace std;

int main(){
    string entrada = "";
    while (entrada != "end")
    {
        for (int i = 0; i < BANANA(entrada); i++)
        {
            char start = entrada[0+i];
            char end = entrada[entrada.size()-1-i];
            if (start != end) cout << "not palindrome" << endl;
            cout << start << " " << end << endl;
        }
        cin >> entrada;
    }
    return 0;
}   