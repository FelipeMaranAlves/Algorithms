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
    int* Mark;
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
    }
    ~GraphList() {
        delete[] Mark;
        delete[] adjList;
        delete[] Parent_Dijkstra;
        delete[] Distances_Dijkstra;
    }

    void setEdge(int i, int j, int wt) {
        Edges new_edge(wt, j);
        adjList[i].push_back(new_edge);
    }

    void setMark(int v, int state) {
        if (v >= 0 && v < numVertex) {
            Mark[v] = state;
        }
    }
    int getMark(int v) { return Mark[v]; }

    int* returnditance() { return Distances_Dijkstra; }

    void Dijkstra(int s) {
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
        H.push({0, s});
        Distances_Dijkstra[s] = 0;

        while (!H.empty()) {
            int v = H.top().second;
            H.pop();
            if (Mark[v] == VISITED) continue;

            Mark[v] = VISITED;

            for (auto w : adjList[v]) {
                int wc = w.GetChild();
                int ww = w.GetWeight();
                if (Mark[wc] == UNVISITED && Distances_Dijkstra[wc] > Distances_Dijkstra[v] + ww) {
                    Distances_Dijkstra[wc] = Distances_Dijkstra[v] + ww;
                    H.push({Distances_Dijkstra[wc], wc});
                }
            }
        }
    }

    void clearGraph() {
        for (int i = 0; i < numVertex; i++) {
            Mark[i] = UNVISITED;
            adjList[i].clear();
            Parent_Dijkstra[i] = -1;
            Distances_Dijkstra[i] = INFINITE;
        }
    }
};

int main() {
    int bigN, n, m, s, t, w, v1, v2; // s -> t
    scanf("%d", &bigN);
    for (int i = 0; i < bigN; i++) {
        scanf("%d %d %d %d", &n, &m, &s, &t);
        GraphList grafo(n);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &v1, &v2, &w);
            grafo.setEdge(v1, v2, w);
            grafo.setEdge(v2,v1,w);
        }
        grafo.Dijkstra(s);
        int* D = grafo.returnditance();
        if (D[t] == INFINITE) {
            cout << "Case #" << i+1 << ": " << "unreachable" << endl;
        } else {
            cout << "Case #" << i+1 << ": " << D[t] << endl;
        }
    }
    return 0;
}

//g++ A.cpp -o A.exe ;Get-Content inputA.txt | ./A.exe