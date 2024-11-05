#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    int x, y ,z;
    int biggest,a ,b, current;
    fin >> x >> y >> z;
    biggest = 0;
    for (int i=0; x*i <= z; i++) {
        for (int j=0; y*j <= z-(x*i); j++) {
            current = (x*i+y*j);
            if (current > biggest) {
                biggest = current;
            }
        }
    }
    fout << biggest;
    return 0;
}