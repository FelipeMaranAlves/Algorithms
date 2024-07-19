#include <bits/stdc++.h>
using namespace std;
//treeArr[curr] is any given node
class setQU
{
private:
    int* treeArr; // parent pointing tree
public:
    int returnParent(int current){return treeArr[current];}
    setQU(int n){
        treeArr = new int[n];
        for (int i = 0; i < n; i++)
        {
            treeArr[i] = -1;
        }
        
    }
    ~setQU(){
        delete[] treeArr;
    }

    int findQU(int curr){
        if (treeArr[curr] == -1){return curr;} // -1 represents "NULL"
        treeArr[curr] = findQU(treeArr[curr]);
        return treeArr[curr];
    }
    void unionQU(int a,int b){
        int rt1 = findQU(a);
        int rt2 = findQU(b);
        if (rt1 != rt2)
        {
            treeArr[rt2] = treeArr[rt1];
        }
    }
};

int main(){

    return 0;
}
