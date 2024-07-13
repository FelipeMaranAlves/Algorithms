#include <bits/stdc++.h>
using namespace std;

#define VISITED 1
#define UNVISITED 0

class Edges
{
private:
    int wt;
    int child;
public:
    Edges();
    ~Edges();
};

class matrixList
{
private:
    int* Mark;
    list<Edges>* adjList;
    int numVertex;

public:
    matrixList() {};
    ~matrixList();

    int first(int v){
        Edges arestas = adjList[v];

    }
};

