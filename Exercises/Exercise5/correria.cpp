#include <bits/stdc++.h>
using namespace std;

#define VISITED 1
#define UNVISITED 0
#define VISITING 2

class Edges
{
private:
    int vert, wt;
public:
    Edges(){
        vert = -1;
        wt = -1;
    };
    Edges(int v,int w){
        vert = v;
        wt = w;
    }
    int vertex(){
        return vert;
    }
    int weight(){
        return wt;
    }
    ~Edges();
};
Edges banana();

class correria
{
private:
    /* data */
public:
    correria(/* args */);
    ~correria();
};

correria::correria(/* args */)
{
}

correria::~correria()
{
}

