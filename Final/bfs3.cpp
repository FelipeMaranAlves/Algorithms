#include <bits/stdc++.h>
using namespace std;

void bfs(int** G,int* Mark,int n){
    for (int i = 0; i < n; i++) {Mark[i] = 0;} //todos nao visitados
    for (int i = 0; i < n; i++) //percorro toda a arvore/floresta
    {
        if (Mark[i]){continue;}
        queue<int> fila;
        fila.push(i);
        Mark[i] = 1;
        while (!fila.empty())
        {
            int s = fila.front();
            fila.pop();
            for (int j = 0; j < n; i++)
            {
                if (!Mark[j] && G[s][j]) {fila.push(j);Mark[j] = 1;}
            }
        }
    }
}


/*
visitodos
v
queue
while (notEmpty)
dequeue
for (j)
g[s][j]
*/