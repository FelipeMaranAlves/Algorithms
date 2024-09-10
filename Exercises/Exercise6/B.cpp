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
            Edges reverse_edge(wt, i);
            adjList[i].push_back(new_edge); 
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
        int n,m,v1,v2,w;
        int biggest = INT32_MIN;
        int reachable_flag = 1;
        while (1)
        {
            scanf("%d %d",&n,&m);
            if (n == 0 && m == 0) break;
            GraphList grafo(n);
            for (int i = 0; i < m; i++)
            {
                scanf("%d %d %d",&v1,&v2,&w); 
                grafo.setEdge(v1,v2,w);
            }
            grafo.Prim(0);
            int* D = grafo.returndistance();
            biggest = INT32_MIN;
            reachable_flag = 1;
            //parte do print e comparacao
            for (int i = 0; i < n; i++)
            {
                if (D[i] == INFINITE) {reachable_flag = 0; break;}
                if (D[i] > biggest) {biggest = D[i];}
            }
            if (reachable_flag){
                printf("%d\n",biggest);
            } else {
                printf("IMPOSSIBLE\n");
            }
            // grafo.~GraphList();
            
        }
        return 0;
    }

    //g++ B.cpp -o B.exe ;Get-Content inputB.txt | ./B.exe