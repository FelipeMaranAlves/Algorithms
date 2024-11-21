#include <bits/stdc++.h>
using namespace std;

#define UNVISITED 0
#define VISITED 1
#define INFINITE INT32_MAX

struct edge
{
    int child;
    int weight;
};


class graphList
{
private:
    int* D;
    int* V;
    int* Mark;
    list<edge>* adjList;
    int numVertex;
    int wtAfterPrim;
public:
    graphList(int n){
        Mark = new int[n];
        adjList = new list<edge>[n];
        D = new int[n];
        V = new int[n];
        int numVertex = n;
        for (int i = 0; i < n; i++)
        {
            Mark[i] = UNVISITED;
        }
    }
    ~graphList(){
        delete[] Mark;
        delete[] adjList;
        delete[] D;
        delete[] V;
    }

    int myweight(){
        int peso = 0;
        for (int i = 0; i < numVertex; i++)
        {
            peso += D[i];
        }
        return peso;
    }

    void setEdge(int a,int b, int w){
        edge newedge;
        newedge.child = b;
        newedge.weight = w;
        adjList[a].push_back(newedge);
    }

    void prim(){
        // cout << "bb" << endl;
        for (int i = 0; i < numVertex; i++)
        {
            D[i] = INFINITE;
            V[i] = -69;
            Mark[i] = UNVISITED;
        }
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        >H;
        H.push({0,{0,0}}); // to começando do primeiro msm pq sim
        D[0] = 0;
        int p,v;
        for (int i = 0; i < numVertex; i++)
        {
            // cout << "aa" << endl;
            do
            {
                if (H.empty()) {return;} // rever isso aq
                pair<int, pair<int, int>> top = H.top();
                H.pop();
                p = top.first;
                v = top.second.first;
            } while (Mark[v] != UNVISITED);
            Mark[v] = VISITED;
            V[v] = p;
            for (auto it : adjList[v])
            {
                int w = it.child;
                int wt = it.weight;
                if (Mark[w] != VISITED && (D[w] > wt))
                {
                    D[w] = wt;
                    H.push({v,{w,D[w]}});
                }
            }
        }
    }
};





int main(){
    cout << "main" << endl;
    int cidades,obras,i,j,p; // aka vertexes and edges, 0-n
    int caso = 0;
    cin >> cidades >> obras;
    while (cidades != 0 && obras != 0) // dar o setdege i,j j,i
    {
        caso++;
        graphList meugrafo(cidades);
        for (int banana = 0; banana < obras; banana++)
        {
            cin >> i >> j >> p;
            meugrafo.setEdge(i,j,p);
            meugrafo.setEdge(j,i,p);
        }
        meugrafo.prim();
        cout << "Caso " << caso << ": " << meugrafo.myweight() << endl;
        cin >> cidades >> obras;
    }
    
    return 0;
}

//g++ ep6.cpp -o ep6exe ;Get-Content input.txt | ./ep6.exe