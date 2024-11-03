#include <fstream>
#include <iostream>
using namespace std;

int main(){
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    int x, y ,z;
    int biggest,a ,b, current;
    fin >> x >> y >> z;
    a = z/x;
    b =0;
    biggest = 0;
    current = (x*a+y*b);
    while (b < (z/y)) {
        if (current > biggest) {
            biggest = current;
        }
        a--;
        current = (x*a+y*b);
        if (z-current > y) {
            b++;
        }
        current = (x*a+y*b);
    }
    fout << biggest;
    return 0;
}