#include <bits/stdc++.h>
using namespace std;

int knapsack(int n,int W,int value_of[],int weight_of[]){
    int** F = new int*[W+1];
    for (int i = 0; i <= W; i++)
    {
        F[i] = new int[n+1];
        for (int j = 0; j <= n; i++)
        {
            if (j == 0 || i == 0) {F[i][j] = 0;} else {F[i][j] = -1;}
        }
        
    }//ja inicializei a matriz com as linhas e colunas do 0 recebendo 0 e o resto recebendo -1
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            int &current = F[i][j];
            int notInsert = F[i-1][j];
            int Insert = F[i-1][j-weight_of[i]];
            if (j <= weight_of[i])
            {
                current = max(notInsert,value_of[i] + Insert);
            } else {current = notInsert;}
            
        }
        
    }
    return F[n][W];
}