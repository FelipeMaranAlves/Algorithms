#include <bits/stdc++.h>
using namespace std;

void bfs(int** G,int n,int* Mark){
    for (int i = 0; i < n; i++) // seto todos para false
    {
        Mark[i] = 0;
    }
    queue<int> fila;
    for (int v = 0; v < n; v++) //garanto que percorro todos os possiveis subgrafos
    {
        if (Mark[v]) {continue;} 
        fila.push(v); //pego um primeiro no qualquer
        Mark[v] = 1;
        // G[s][j]
        while(!fila.empty()){ //cobre a subarvore
            int s = fila.front();
            fila.pop();
            for (int j = 0; j < n; j++)
            {
                if (!Mark[j] && G[s][j]) {
                    fila.push(j);
                    Mark[j] = 1;
                    }
            }
        }
    }
}


