#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    for (int i = 1; i <= 10; i++)
    {
        int a = i;
        for (int j = 1; j <= 10; j++)
        {
            cout << setw(3) << a << " ";
            a += i;
        }
        cout << endl;
    }
    
    return 0;
}