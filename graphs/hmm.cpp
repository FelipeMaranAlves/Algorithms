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
    Edges(int w, int c) : wt(w), child(c) {}
    int GetWeight() const { return wt; }
    int GetChild() const { return child; }
};

class setQU
{
private:
    vector<int> treeArr; // parent pointing tree
public:
    setQU(int n) : treeArr(n, -1) {}
    
    int findQU(int curr) {
        if (treeArr[curr] == -1) {
            return curr; // -1 represents "NULL"
        }
        treeArr[curr] = findQU(treeArr[curr]);
        return treeArr[curr];
    }
    
    void unionQU(int a, int b) {
        int rt1 = findQU(a);
        int rt2 = findQU(b);
        if (rt1 != rt2) {
            treeArr[rt2] = rt1;
        }
    }
};

class GraphList
{
private:
    vector<int> Mark; // the array for the representation of states
    vector<list<Edges>> adjList; 
    int numVertex;
    vector<int> P;
    vector<int> D;
public:
    GraphList(int n) : numVertex(n), Mark(n, UNVISITED), adjList(n), P(n), D(n) {}

    void setEdge(int i, int j, int wt) { // directed
        adjList[i].emplace_back(wt, j);
    }

    void setMark(int v, int state) {
        if (v >= 0 && v < numVertex) {
            Mark[v] = state;
        }
    }

    int getMark(int v) { return Mark[v]; }

    int* returndistance() { return D.data(); }
    
    GraphList kruskal() {
        int edgecnt = 1;
        int totalwt = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> H;
        GraphList G(numVertex);
        setQU ds(numVertex);
        
        for (int i = 0; i < numVertex; i++) {
            for (const auto& w : adjList[i]) {
                H.push({w.GetWeight(), {i, w.GetChild()}});
            }
        }
        
        int numMST = 0;
        while (!H.empty() && numMST < numVertex - 1) {
            auto top = H.top();
            H.pop();
            int wt = top.first;
            int v = top.second.first;
            int u = top.second.second;
            if (ds.findQU(v) != ds.findQU(u)) {
                totalwt += wt;
                ds.unionQU(v, u);
                G.setEdge(v, u, wt);
                numMST++;
            }
        }

        if (numMST != numVertex - 1) {
            // If we don't have enough edges for a valid MST, return an empty graph
            return GraphList(0);
        }
        
        return G;
    }

    void printGraph() {
        for (int i = 0; i < numVertex; ++i) {
            cout << "Vertex " << i << ":\n";
            for (const auto& edge : adjList[i]) {
                cout << edge.GetChild() << " " << edge.GetWeight() << "\n";
            }
        }
    }
};

// A = 0, B = 1, C = 2, D = 3, E = 4
int main() {
    const int A = 0;
    const int B = 1;
    const int C = 2;
    const int D = 3;
    const int E = 4;
    
    GraphList grafo(5);
    grafo.setEdge(A, B, 10);
    grafo.setEdge(A, D, 20);
    grafo.setEdge(A, C, 3);
    grafo.setEdge(B, D, 5);
    grafo.setEdge(C, B, 2);
    grafo.setEdge(C, E, 15);
    grafo.setEdge(D, E, 11);
    
    GraphList newgraph = grafo.kruskal();
    cout << "MST created by Kruskal's Algorithm:\n";
    newgraph.printGraph();
    
    return 0;
}

//g++ hmm.cpp -o hmm.exe ; ./hmm.exe