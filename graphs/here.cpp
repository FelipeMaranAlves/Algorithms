#include <bits/stdc++.h>
using namespace std;

#define VISITED 1
#define UNVISITED 0
#define INFINITE INT32_MAX
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

    void setEdge(int i, int j,int wt){ //directed
        Edges new_edge(wt,j);
        adjList[i].push_back(new_edge);
    }
    void setMark(int v,int state){
        if (-1< v < numVertex) { Mark[v] = state;}
    }
    int getMark(int v){return Mark[v];}



    void BSF(int start){//v eh um indice de adjList w eh um edges
        queue<int> q;
        q.push(start);
        Mark[start] = VISITED;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            //previsit
            for (auto w : adjList[v])
            {
                if (Mark[w.GetChild() == UNVISITED])
                {
                    Mark[w.GetChild()] = VISITED;
                    q.push(w.GetChild());
                }
                
            }
            //postvisit
        }
        
    }
    void DFS(int v){ //v is the index of adjList 
        //previsit
        Mark[v] = VISITED;
        for (auto w : adjList[v])
        {
            if (Mark[w.GetChild()] == UNVISITED)
            {
                DFS(w.GetChild());
            }
        }
        //postvisit
    }
    void graphTraverseBFS(){
        for (int v = 0; v < numVertex; v++)
        {
            Mark[v] = UNVISITED;
        }
        for (int v = 0; v < numVertex; v++)
        {
            if (Mark[v] == UNVISITED)
            {
                BSF(v);
            }
            
        }
    }
        void graphTraverseDFS(){
        for (int v = 0; v < numVertex; v++)
        {
            Mark[v] = UNVISITED;
        }
        for (int v = 0; v < numVertex; v++)
        {
            if (Mark[v] == UNVISITED)
            {
                DFS(v);
            }
            
        }
    }
    //toposort fazer dnv se precisar
    // void clearGraph(); ele se deleta?
    
};

