#include <bits/stdc++.h>
using namespace std;

#define VISITED 1
#define UNVISITED 0
#define INFINITE INT32_MAX

class Edges {
private:
    int wt;
    int child;
public:
    Edges(int w, int c) { wt = w; child = c; }
    int GetWeight() { return wt; }
    int GetChild() { return child; }
};

class GraphList {
private:
    int* Mark; // the array for the representation of states
    list<Edges>* adjList;
    int numVertex;
    int* Parent_Dijkstra;
    int* Distances_Dijkstra;
public:
    GraphList(int n) {
        Mark = new int[n];
        adjList = new list<Edges>[n];
        numVertex = n;
        for (int i = 0; i < n; ++i) {
            Mark[i] = UNVISITED;
        }
        Parent_Dijkstra = new int[n];
        Distances_Dijkstra = new int[n];
    };
    ~GraphList() {
        delete[] Mark;
        delete[] adjList;
        delete[] Parent_Dijkstra;
        delete[] Distances_Dijkstra;
    };

    void setEdge(int i, int j, int wt) { // directed
        Edges new_edge(wt, j);
        adjList[i].push_back(new_edge);
    }

    void setMark(int v, int state) {
        if (-1 < v && v < numVertex) { Mark[v] = state; }
    }

    int getMark(int v) { return Mark[v]; }

    int* returnditance() { return Distances_Dijkstra; }

    void BFS(int start) { // v is an index of adjList, w is an edge
        queue<int> q;
        q.push(start);
        Mark[start] = VISITED;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto w : adjList[v]) {
                if (Mark[w.GetChild()] == UNVISITED) {
                    Mark[w.GetChild()] = VISITED;
                    q.push(w.GetChild());
                }
            }
        }
    }

    void DFS(int v) { // v is the index of adjList
        Mark[v] = VISITED;
        for (auto w : adjList[v]) {
            if (Mark[w.GetChild()] == UNVISITED) {
                DFS(w.GetChild());
            }
        }
    }

    void graphTraverseBFS() {
        for (int v = 0; v < numVertex; v++) {
            Mark[v] = UNVISITED;
        }
        for (int v = 0; v < numVertex; v++) {
            if (Mark[v] == UNVISITED) {
                BFS(v);
            }
        }
    }

    void graphTraverseDFS() {
        for (int v = 0; v < numVertex; v++) {
            Mark[v] = UNVISITED;
        }
        for (int v = 0; v < numVertex; v++) {
            if (Mark[v] == UNVISITED) {
                DFS(v);
            }
        }
    }

    void Dijkstra(int s) { // the size of D[] is numvertex
        for (int i = 0; i < numVertex; i++) {
            Distances_Dijkstra[i] = INFINITE;
            Parent_Dijkstra[i] = -1;
            Mark[i] = UNVISITED;
        }
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > H;
        H.push({0, s}); // (distance, vertex)
        Distances_Dijkstra[s] = 0;

        while (!H.empty()) {
            int v = H.top().second;
            int dist = H.top().first;
            H.pop();

            if (Mark[v] == VISITED) continue;

            Mark[v] = VISITED;

            for (auto w : adjList[v]) {
                int u = w.GetChild();
                int weight = w.GetWeight();
                if (Mark[u] == UNVISITED && Distances_Dijkstra[u] > dist + weight) {
                    Distances_Dijkstra[u] = dist + weight;
                    Parent_Dijkstra[u] = v;
                    H.push({Distances_Dijkstra[u], u});
                }
            }
        }
    }
};

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
    grafo.Dijkstra(A);
    int* distances = grafo.returnditance();
    for (int i = 0; i < 5; i++) {
        cout << distances[i] << " ";
    }

    return 0;
}

//g++ gptway.cpp -o gptway.exe ; ./gptway.exe