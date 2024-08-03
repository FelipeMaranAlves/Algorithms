#include <bits/stdc++.h>
using namespace std;

void bsf(int** G,int n,int* Mark){
    for (int i = 0; i < n; i++)
    {
        Mark[i] = 0;
    }
    for (int i = 0; i < n; i++) // para percorrer todos os possiveis subgrafos
    {
        if (Mark[i]) {continue;};
        queue<int> fila; //uma fila que vai armazenar indices que representam os proximos nos a serem visitados
        fila.push(Mark[i]);
        Mark[i] = 1;
        while (!fila.empty()) //fazer o while pra percorrer a subarvore toda
        {
            int s = fila.front();
            fila.pop();
            for (int j = 0; j < n; j++)
            {
                if (G[s][j] && !Mark[j]){ // se ele existir na matriz e seu valor estiver 1 na lista de marcaco
                    fila.push(i);
                    Mark[j] = 1;
                    }
                
            }
        }
    }
    
}

int main() {
    int n = 5; // Number of nodes
    // Create an adjacency matrix for the graph
    int** G = new int*[n];
    for (int i = 0; i < n; i++) {
        G[i] = new int[n];
    }
    
    // Initialize the adjacency matrix (Example graph)
    // 0 -- 1
    // |    |
    // 2 -- 3
    // |
    // 4
    G[0][0] = 0; G[0][1] = 1; G[0][2] = 1; G[0][3] = 0; G[0][4] = 0;
    G[1][0] = 1; G[1][1] = 0; G[1][2] = 0; G[1][3] = 1; G[1][4] = 0;
    G[2][0] = 1; G[2][1] = 0; G[2][2] = 0; G[2][3] = 1; G[2][4] = 1;
    G[3][0] = 0; G[3][1] = 1; G[3][2] = 1; G[3][3] = 0; G[3][4] = 0;
    G[4][0] = 0; G[4][1] = 0; G[4][2] = 1; G[4][3] = 0; G[4][4] = 0;

    // Create the Mark array
    int* Mark = new int[n];

    // Perform BFS
    bsf(G, n, Mark);

    // Print the Mark array to see which nodes were visited
    cout << "Nodes visited (1 means visited):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": " << Mark[i] << endl;
    }

    // Clean up memory
    for (int i = 0; i < n; i++) {
        delete[] G[i];
    }
    delete[] G;
    delete[] Mark;

    return 0;
}