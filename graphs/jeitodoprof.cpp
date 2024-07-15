#include <bits/stdc++.h>
using namespace std;

#define UNVISITED 0
#define VISITED 1

/*
Operations
int n(Graph g)
int e(Graph g)
int first(Graph g, int v)
int next(Graph g, int v, int w)
void setEdge(Graph g, int i, int j, int wt)
void delEdge(Graph g, int i,int j)
boolean isEdge(Graph g, int i,int j)
int weight(Graph g, int i, int j)
void setMark(Graph g,int v, int val)
int getMark(Graph g,int v)
*/

class MatrixGraph
{
private:
    int** matrix;
    int numEdge;
    int* Mark;
    int numVertex;

public:
    MatrixGraph(int n){
        numVertex = n;
        numEdge = 0;
        matrix = (int**)malloc(n*sizeof(int*));
        Mark = (int*)malloc(sizeof(int)*n);
        for (int i = 0; i < n; i++)
        {
            matrix[i] = (int*)malloc(sizeof(int)*n);
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = 0;
            }
            
        }
        for (int i = 0; i < numVertex; i++)
        {
            Mark[i] = UNVISITED;//terminar a inicializacao do mark como unvisited
        }
        
    }
    ~MatrixGraph(){
        free(Mark);
        for (int i = (numVertex-1); i >= 0; i--)
        {
            free(matrix[i]);
        }
        //falta fazer o free da matrix mas n to sabendo como deixar o n aqui dentro
    }

    int n(){
        return numVertex;
    }
    int e(){
        return numEdge;
    }

    //return first neightbor of "v"
    //Implicit assumption: 0 denotes the absence of an edge between two nodes
    int first(int v){
        for (int i = 0; i < (numVertex-1); i++)
        {
            if (matrix[v][i] != 0)
            {
                return i;
            }
        }
        return numVertex; // return n if none
    }
    //Return v’s next neighbor after w
    //Implicit assumption: 0 denotes the absence of an edge between two nodes
    int next(int v, int w){
        for (int i = (w+1); i < (numVertex-1) ; i++)
        {
            if (matrix[v][i] != 0)
            {
                return i;
            }
        }
        return numVertex;   
    }

    //set edge (i,j) to "wt"
    void setEdge(int i, int j, int wt){
        if (wt == 0)
        {
            return;
        }
        if (matrix[i][j] == 0)
        {
            numEdge++;
        }
        matrix[i][j] = wt;
    }

    void delEdge(int i, int j){
        if (matrix[i][j])
        {
            numEdge--;
        }
        matrix[i][j] = 0;
    }

    void DFS(int v){
        //previsit ??
        Mark[v] = VISITED;
        int w = first(v);
        while (w < numVertex)
        {
            if (Mark[w] == UNVISITED)
            {
                DFS(w);
            }
            w = next(v,w);
        }
        //postvisit ?? provavelmente usa esses pre/post pra printar ou fazer sla oq
    }


    void graphTraverseDFS(){
        for (int v = 0; v < (numVertex-1); v++)
        {
            Mark[v] = UNVISITED;
        }
        for (int v = 0; v < (numVertex-1); v++)
        {
            if (Mark[v] == UNVISITED)
            {
                DFS(v); //traverse here in this case dfs
            }
            
        }
        
    }

    void BSF(int start){
        queue<int> q;
        q.push(start);
        Mark[start] = VISITED;
        while (q.size() > 0)
        {
            int v = q.front();
            q.pop();
            //previsit(v) ??
            int w = first(v);
            while (w < numVertex)
            {
                if (Mark[w] == UNVISITED)
                {
                    Mark[w] = VISITED;
                    q.push(w);
                }
                w = next(v,w);
            }
            //postvisit(v) ?
        }
        
    }

    void graphTraverseBFS(){
        for (int v = 0; v < (numVertex-1); v++)
        {
            Mark[v] =UNVISITED;
        }
        for (int v = 0; v < (numVertex-1); v++)
        {
            if (Mark[v] == UNVISITED)
            {
                BSF(v);
            }
        }
    }

    void toposort(int v,stack<int> s){
        Mark[v] = VISITED;
        int w = first(v);
        while (w < numVertex)
        {
            if (Mark[w] == UNVISITED)
            {
                toposort(w,s);
            }
            w = next(v,w);
        }
        s.push(v);
    }

};


int main(){
    
    return 0;
}