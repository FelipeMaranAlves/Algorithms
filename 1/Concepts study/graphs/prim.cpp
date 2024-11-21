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
    int* V;  // V array for Prim's algorithm
    int* Distances_Prim;
public:
    GraphList(int n) {
        Mark = new int[n];
        adjList = new list<Edges>[n];
        numVertex = n;
        for (int i = 0; i < n; ++i) {
            Mark[i] = UNVISITED;
        }
        V = new int[n];
        Distances_Prim = new int[n];
    }
    ~GraphList() {
        delete[] Mark;
        delete[] adjList;
        delete[] V;
        delete[] Distances_Prim;
    }

    void setEdge(int i, int j, int wt) { // directed
        Edges new_edge(wt, j);
        adjList[i].push_back(new_edge);
        // Since this is an undirected graph, add the reverse edge as well
        Edges reverse_edge(wt, i);
        adjList[j].push_back(reverse_edge);
    }

    void setMark(int v, int state) {
        if (v >= 0 && v < numVertex) {
            Mark[v] = state;
        }
    }
    int getMark(int v) { return Mark[v]; }

    int* returndistance() { return Distances_Prim; }
    int* returnV() { return V; }

    void Prim(int s) {
        for (int i = 0; i < numVertex; i++) {
            Distances_Prim[i] = INFINITE;
            V[i] = -1;
            Mark[i] = UNVISITED;
        }
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > H;
        H.push({0, s}); // (distance, vertex)
        Distances_Prim[s] = 0;
        V[s] = s;

        while (!H.empty()) {
            int v = H.top().second;
            H.pop();
            if (Mark[v] == VISITED) continue;

            Mark[v] = VISITED;

            for (auto w : adjList[v]) {
                int wc = w.GetChild();
                int ww = w.GetWeight();
                if (Mark[wc] == UNVISITED && Distances_Prim[wc] > ww) {
                    Distances_Prim[wc] = ww;
                    V[wc] = v;
                    H.push({Distances_Prim[wc], wc});
                }
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
    grafo.Prim(A);
    int* distances = grafo.returndistance();
    int* V = grafo.returnV();
    for (int i = 0; i < 5; i++) {
        cout << distances[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << V[i] << " ";
    }
    cout << endl;

    return 0;
}

//g++ prim.cpp -o prim.exe ; ./prim.exe