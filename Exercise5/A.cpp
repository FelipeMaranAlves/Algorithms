#include <bits/stdc++.h>
using namespace std;

#define VISITED 1
#define UNVISITED 0
#define VISITING 2

class AdjListGraph {
private:
    vector<vector<int>> adjList;
    int numVertex;
    vector<int> mark;

public:
    AdjListGraph(int n) : numVertex(n), adjList(n), mark(n, UNVISITED) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Para grafos não-dirigidos
    }

    void setMark(int v, int val) {
        mark[v] = val;
    }

    int getMark(int v) {
        return mark[v];
    }

    void DFS(int v) {
        mark[v] = VISITED;
        for (int w : adjList[v]) {
            if (mark[w] == UNVISITED) {
                DFS(w);
            }
        }
    }

    void BFS(int start) {
        queue<int> q;
        q.push(start);
        mark[start] = VISITED;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int w : adjList[v]) {
                if (mark[w] == UNVISITED) {
                    mark[w] = VISITED;
                    q.push(w);
                }
            }
        }
    }

    void graphTraverseBFS() {
        fill(mark.begin(), mark.end(), UNVISITED);
        int count = 0;
        for (int v = 0; v < numVertex; v++) {
            if (mark[v] == UNVISITED) {
                BFS(v);
            }
        }
    }

        void toposort(int v,stack<int> s){
        mark[v] = VISITED;
        int w = first(v);
        while (w < numVertex)
        {
            if (mark[w] == UNVISITED)
            {
                toposort(w,s);
            }
            w = next(v,w);
        }
        s.push(v);
    }

    void printEdges() {
        for (int i = 0; i < numVertex; i++) {
            cout << "Vertex " << i << ":";
            for (int j : adjList[i]) {
                cout << " " << j;
            }
            cout << endl;
        }
    }
};



int main() {
    AdjListGraph grafo(5);
    grafo.addEdge(0, 1);
    grafo.addEdge(0, 2);
    grafo.addEdge(1, 3);
    grafo.addEdge(2, 4);
    std::lis
    cout << "Adjacency List:" << endl;
    grafo.printEdges();
    return 0;
}




//g++ A.cpp -o  A.exe ; ./A.exe