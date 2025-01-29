#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");
    int k,n;
    fin >> k >> n;
    vector<vector<int>> placements;
    int** placements2 = new int*[k];
    
    for (int i = 0; i < k; i++)
    {
        for (int i = 0; i < n; i++)
        {
            fin >> placements2[k][n];
            cout << placements2[k][n];
        }
    }
    return 0;
}