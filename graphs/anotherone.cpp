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
    Edges(int w,int c){ wt = w; child = c;}
    int GetWeight(){return wt;}
    int GetChild(){return child;}
};

// class Vertex
// {
// private:
//     int state;
//     //possibly a name (if the name is a string i could store the hash function that generates the index of it's position in the Mark array(wich now is an overall storage for information))
// public:
//     Vertex(int vis){ state = vis;}
//     void setState(int a){state = a;}
// };



class GraphList
{
private:
    int* Mark; // the array for the representation of states
    list<Edges>* adjList; 
    int numVertex;

public:
    GraphList(int n){
        // Mark = (int*)malloc(sizeof(int)*n);
        // adjList = (list<Edges>*)malloc(sizeof(list<Edges>)*n); // estou assumindo que inicializa com null certin ou size 0 enfim
        Mark = new int[n] ;
        adjList = new list<Edges>[n];
        numVertex = n;
        for (int i = 0; i < n; ++i) {
            Mark[i] = UNVISITED;
        }
    };
    ~GraphList(){
        // free(Mark);
        // free(adjList);
        delete[] Mark;
        delete[] adjList;
    };

    int first(int v){
        if (adjList[v].empty()) {return numVertex;};
        return adjList[v].front().GetChild(); //esse cara
    }

    int next(int v){
        for (auto it : adjList[v])//(auto it = adjList[v].begin(); it != adjList[v].end(); ++it) outro jeito
        {
            // PAREI AQUI
        }
        
    }

    void setEdge(int i, int j,int wt){ //directed
        Edges new_edge(wt,j);
        adjList[i].push_back(new_edge);
    }
    void setMark(int v,int state){
        if (-1< v < numVertex) { Mark[v] = state;}
    }
    int getMark(int v){return Mark[v];}



    void BFS(int start){
        queue<int> q;
        q.push(start);
        Mark[start] = VISITED;
        while (/* condition */)
        {
            /* code */
        }
        
    }
    // void BFS(int start);
    // void graphTraverse();
    // void clearGraph();
    
};

