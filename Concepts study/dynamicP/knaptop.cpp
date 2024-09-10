#include <bits/stdc++.h>
using namespace std;

class sack
{
private:
    int** F;
    int n;
    int W;
public:
    sack(int n,int W) : n(n), W(W) {
        F = new int*[n+1];
        for (int i = 0; i <= n; i++)//0-n
        {
            F[i] = new int[W+1]; //0-W
            for (int j = 0; j <= W; j++)
            {
                if(i == 0 || j == 0){F[i][j] = 0;} else {F[i][j] = -1;}
                // inicializando os valores pra -1 pra raber reconhecer quem nao foi chamado e 0 na i=0 e j =0
            }
            
        }
    }
    ~sack(){
        for (int i = 0; i <= n; i++)//0-n
        {
            delete F[i];
        }
        delete F;
    }
    int bestvalue(int i,int j,int* w,int* v){
        int value;
        if (F[i][j] < 0)
        {
            if (j < w[i])
            {
                value = bestvalue(i-1,j,w,v);//o cara anterior
            } else {
                value = max(bestvalue(i-1,j,w,v),v[i]+bestvalue(i-1,j-w[i],w,v));
            }
            F[i][j] = value;
        }
        return F[i][j];
    }
};

int main(){
    int cases, W, n, currWt, currVal;
    int* weights;
    int* values;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> W >> n;
        weights = new int[n+1];
        values = new int[n+1];
        for (int j = 1; j <= n; j++) // corrigi o indice aq
        {
            cin >> currWt >> currVal;
            weights[j] = currWt;
            values[j] = currVal;
        }

        // Debug print to verify input

        sack saco(n, W);
        cout << saco.bestvalue(n,W,weights, values) << "\n";
        delete[] weights;
        delete[] values;
    }
    
    return 0;
}

//g++ knaptop.cpp -o knaptop.exe ; Get-Content inputsaco.txt | ./knaptop.exe