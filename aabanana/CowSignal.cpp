#include <fstream>
#include <string.h>
using namespace std;

int main(){
    ifstream fin("cowsignal.in");
    ofstream fout("cowsignal.out");
    
    int m,n,k;
    fin >> m >> n >> k;
    for (int i = 0; i < m; i++)
    {
        string line,newline;
        fin >> line;
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < k; l++)
            {
                newline += line[j];
            }
        }
        for (int l = 0; l < k; l++)
        {
            fout << newline << endl;
        }
    }
    return 0;
}