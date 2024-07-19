#include <bits/stdc++.h>
using namespace std;

//currently from 0 to n-1
class subsetQF
{
private:
    int* representative;
    list<int>* sets;
public:
    subsetQF(int n){
        representative = new int[n];
        sets = new list<int>[n];
        for (int i = 0; i < n; i++)
        {
            representative[i] = i;//at first, i represents i
            sets[i].push_back(i);
        }
        
    }
    list<int>& returngivenset(int a){
        return sets[representative[a]];
    };
    ~subsetQF(){
        delete[] sets;
        delete[] representative;
    };

    int findQF(int current){ return representative[current];};
    
    void unionQF(int a,int b){//rep e o representante, que por sua vez eh um indice que vai apontar to wich set should I look for a given number
        int rep1 = findQF(a);int rep2 = findQF(b);
        if (rep1 != rep2)
        {
            if (sets[rep1].size() > sets[rep2].size()) // set1 > set2
            {
                for (auto it :sets[rep2]){
                    representative[it] = rep1;
                }
                sets[rep1].splice(sets[rep1].end(),sets[rep2]);// everyone from the second three now is on the first one, or at the very least are in the same set o vertexes wich will be used to build said three
                sets[rep2].clear();
            } else { // set2 > set1
               for (auto it :sets[rep1]){
                    representative[it] = rep2;
                }
                sets[rep2].splice(sets[rep2].end(),sets[rep1]); 
                sets[rep1].clear();
            }
            
        }
        
    };
};




int main(){
    subsetQF grafoteste(6); // de 0 a n-1
    grafoteste.unionQF(1-1,4-1);
    grafoteste.unionQF(4-1,5-1);
    grafoteste.unionQF(1-1,2-1);
    grafoteste.unionQF(3-1,6-1);
    grafoteste.unionQF(1-1,3-1);
    for (auto it : grafoteste.returngivenset(1))
    {
        cout << it+1 << " ";
    }
    cout << endl;
    return 0;
}

//g++ quickfind.cpp -o quickfind.exe ; ./quickfind.exe