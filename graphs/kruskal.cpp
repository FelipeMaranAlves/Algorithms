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
    
    GraphList kruskal(){
        int edgecnt = 1;
        int totalwt = 0;
        priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
        >H;
        GraphList G(numVertex);
        setQU ds(numVertex);
        for (int i = 0; i < numVertex; i++)
        {
            for (auto w : adjList[i])
            { 
                H.push({i,{w.GetChild(),w.GetWeight()}});
                edgecnt++;
            }
        }
        int numMST = numVertex;
        while (numMST > 1)
        {
            if (H.empty())
            {
                //intead of returning the state here i would rather check in the main if it has infinite distance 
                return;
            }
            pair<int, pair<int, int>> top = H.top();
            H.pop();
            int v = top.first;
            int u = top.second.first;
            int wt = top.second.second;
            if (ds.findQU(v) != ds.findQU(u))
            {
                totalwt += wt;
                ds.unionQU(v,u);
                G.setEdge(v,u,wt);
                numMST--;
            }
        }
        return G;
    }
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
    GraphList newgraph = grafo.kruskal();
    
    return 0;
}

//g++ anotherone.cpp -o anotherone.exe ; ./anotherone.exe