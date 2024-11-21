#include <bits/stdc++.h>
using namespace std;

#define VISITED 1
#define UNVISITED 0
#define INFINITE INT32_MAX
class Edges
{
private:
    int wt;
    int child;
public:
    Edges(int w,int c){ wt = w; child = c;}
    int GetWeight(){return wt;}
    int GetChild(){return child;}
};




class GraphList
{
private:
    int* Mark; // the array for the representation of states
    list<Edges>* adjList; 
    int numVertex;
    int* P;
    int* D;
public:
    GraphList(int n){
        // Mark = (int*)malloc(sizeof(int)*n);
        // adjList = (list<Edges>*)malloc(sizeof(list<Edges>)*n); // estou assumindo que inicializa com null certin ou size 0 enfim
        Mark = new int[n] ;
        adjList = new list<Edges>[n];
        numVertex = n;
        for (int i = 0; i < n; ++i) {
            Mark[i] = UNVISITED;
        }
        P = new int[n];
        D = new int[n];
    };
    ~GraphList(){
        // free(Mark);
        // free(adjList);
        delete[] Mark;
        delete[] adjList;
        delete[] P;
        delete[] D;
    };

    void setEdge(int i, int j,int wt){ //directed
        Edges new_edge(wt,j);
        adjList[i].push_back(new_edge);
    }
    void setMark(int v,int state){
        if (-1< v < numVertex) { Mark[v] = state;}
    }
    int getMark(int v){return Mark[v];}

    int* returnditance(){return D;}
    
    void Dijkstra(int s){ // the sizeof D[] is numvertex
        for (int i = 0; i < numVertex; i++)
        {
            D[i] = INFINITE;
            P[i] = -1;
            Mark[i] = UNVISITED;
        }
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        >H;
        H.push({s,{s,0}}); // (predecessor (vertice, distancia))
        D[s] = 0;
        int v, p;
        for (int i = 0; i < numVertex; i++)
        {
            do
            {
                if (H.empty()) return;
                auto saida = H.top();
                H.pop();
                    p = saida.first;
                v = saida.second.first;
            } while (Mark[v] == VISITED);
            Mark[v] == VISITED;
            P[v] = p;
            for (auto w : adjList[v])
            {
                int wc = w.GetChild();
                int ww = w.GetWeight();
                if(Mark[wc] != VISITED && (D[wc] > D[v] + ww)){
                    D[wc] = D[v] + ww;
                    H.push({v,{wc,D[wc]}});
                }
            }     
        }
    }
    //toposort fazer dnv se precisar
    // void clearGraph(); ele se deleta?
    
};

//A = 0, B = 1, C = 2, D = 3, E = 4
int main(){
    const int A = 0;
    const int B = 1;
    const int C = 2;
    const int D = 3;
    const int E = 4;
    GraphList grafo(5);
    grafo.setEdge(A,B,10);
    grafo.setEdge(A,D,20);
    grafo.setEdge(A,C,3);
    grafo.setEdge(B,D,5);
    grafo.setEdge(C,B,2);
    grafo.setEdge(C,E,15);
    grafo.setEdge(D,E,11);
    grafo.Dijkstra(A);
    int* distances = grafo.returnditance();
    for (int i = 0; i < 5; i++)
    {
        cout << distances[i] << " ";
    }
    
    return 0;
}

//g++ anotherone.cpp -o anotherone.exe ; ./anotherone.exe