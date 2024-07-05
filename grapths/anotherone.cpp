#include <bits/stdc++.h>
using namespace std;

#define VISITED 1
#define UNVISITED 0

class matrixList
{
private:
    vector<int> Mark;
    vector<vector<int>> adjList;
    int numVertex;

public:
    matrixList(int n) : numVertex(n), adjList(n), Mark(n,UNVISITED) {};
    ~matrixList();
};