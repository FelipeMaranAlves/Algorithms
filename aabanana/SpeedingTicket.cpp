//Speeding Ticket
#include <fstream>
#include <vector>
using namespace std;

int main(){
    ifstream fin("shell.in");
    ofstream fout("shell.out");
    int n, m;
    fin >> n >> m;
    vector<int> Data;// the pair positions with indicies up to n-1 represent the segment of the road the ood ones their allowed speed limit from n+1 upwards they represent the Cow's real segments and positions
    for (int i = 0; i < n+m; i++) 
    {
        int temp1, temp2;
        fin >> temp1 >>temp2;
        Data.push_back(temp1), Data.push_back(temp2);
    }
    for (int i = 0; i < count; i++)
    {
        /* code */
    }
    
    
    return 0;
}