#include <iostream>
#include <vector>
using namespace std;

#define VISITED 1
#define UNVISITED 0

class AdjListGraph {
private:
    vector<vector<int>> adjList;
    int numVertex;
    vector<int> mark;

public:
    AdjListGraph(int n) : numVertex(n), adjList(n, vector<int>(1, 1)), mark(n, UNVISITED) {}

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

    int graphTraverseBFS() {
        fill(mark.begin(), mark.end(), UNVISITED);
        int count = 0;
        for (int v = 0; v < numVertex; v++) {
            if (mark[v] == UNVISITED) {
                BFS(v);
                count++;
            }
        }
        return count;
    }
};

int main() {
    int cases, vertexes, edges, u, v;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        cin >> vertexes >> edges;
        AdjListGraph grafo(vertexes);
        for (int j = 0; j < edges; j++) {
            cin >> u >> v;
            grafo.addEdge(u, v);
        }
        cout << grafo.graphTraverseBFS() << endl;
    }
    return 0;
}

//g++ teste2.cpp -o teste2.exe;Get-Content inputteste.txt | ./teste2.exe