//Speeding Ticket
#include <fstream>
#include <vector>
using namespace std;

int main(){
    ifstream fin("shell.in");
    ofstream fout("shell.out");
    int n, m;
    fin >> n >> m;
    vector<int> RoadData, CowData;
    for (int i = 0; i < n; i++) 
    {
        int temp1, temp2;
        fin >> temp1 >>temp2;
        RoadData.push_back(temp1), RoadData.push_back(temp2);
    }
    for (int i = 0; i < m; i++)
    {
    {
        int temp1, temp2;
        fin >> temp1 >>temp2;
        CowData.push_back(temp1), CowData.push_back(temp2);
    }
    int currentRoadSegment = 0;
    int ExceededSpeed = 0;
    int k;
    
    
    return 0;
}