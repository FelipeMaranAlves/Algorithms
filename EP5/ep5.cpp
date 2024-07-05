#include <bits/stdc++.h>
using namespace std;

#define VISITED 1
#define UNVISITED 0

struct marks
{
    int relativeheight;
    int visited;
};


class graphMatrix
{
private:
    int* pred;
    int numVertex;
    int numEdges;
    marks* Mark;
    int** matrix;
public:
    graphMatrix(int n){
    numVertex = n;
    numEdges = 0;
    pred = (int*) malloc(sizeof(int)*n);
    Mark = (marks*) malloc(sizeof(marks)*n);
    for (int i = 0; i < n; i++)
    {
        Mark->visited = UNVISITED;
        Mark->relativeheight = -1;
    }
    
    matrix = (int**) malloc(sizeof(int*)*n);
    for (int i = 0; i < numVertex; i++)
    {
        matrix[i] = (int*) malloc(sizeof(int)*n);
    }
    
    };
    ~graphMatrix(){
        free(Mark);
        for (int i = 0; i < numVertex; i++)
        {
            free(matrix[i]);
        }
        free(matrix);
    };

    int first(int v){
        for (int i = 0; i < (numVertex-1); i++)//(numVertex-1)
        {
            if (matrix[v][i] != 0){
                return i;
            }
        }
        return numVertex;
    }

    int next(int v,int w){
        for (int i = w+1; i < (numVertex-1); i++)//(numVertex-1)
        {
            if (matrix[v][i] != 0){
                return i;
            }
        }
        return numVertex;
    }

    void setEdge(int i, int j, int wt){
        if(wt==0){
            return;
        }
        if (matrix[i][j] == 0)
        {
            numEdges++;
        }
        matrix[i][j] = wt;
    }

    void delEdge(int i, int j){
        if (matrix[i][j] != 0)
        {
            numEdges--;
        }
        matrix[i][j] = 0;
    }

    void BSF(int start, int desired){
        queue<int> q;
        q.push(start);
        Mark[start].visited = VISITED;
        while (!q.empty()) // n tenho certeza em qual loop botar o contador que vai servir como altura
        { // botar um if tem altura na hora de atribuir
            int v = q.front();
            q.pop();
            //previsit
            int w = first(v);
            while (w < numVertex)
            {
                if (Mark[w].visited == UNVISITED)
                {
                    pred[w] = v;
                    Mark[w].visited = VISITED;
                    q.push(w);
                }
                w = next(v,w);
            }
            //postVIsit
        }
    }
    //na main se a dist ficar como -1 vou saber q n da pra chegar
    void graphTraverseBSF(int banana, int desired){
        for (int v = 0; v < numVertex; v++)
        {
            Mark[v].visited = UNVISITED;
            Mark[v].relativeheight = -1;
        }
        if (Mark[banana].visited == UNVISITED) // provavelmente vai ser aqui meu pulo do gato
        {
            BSF(banana, desired);
        }
        
    }

    void printpath(int desired, int start){
        printf("%d ",pred[desired]);

    }
};



int main(){
    int cases,vertexes,edges,a,b,perguntas,s,t;
    scanf("%d",&cases);
    for (int i = 0; i < cases; i++)
    {
        printf("Caso %d",i+1);
        scanf("%d %d",&vertexes,&edges);
        graphMatrix grafo(vertexes);
        for (int i = 0; i < edges; i++)
        {
            scanf("%d %d",&a,&b);
            grafo.setEdge(a,b,1);
            grafo.setEdge(b,a,1);
        }//grafo criado
        
        scanf("%d",&perguntas);
        for (int i = 0; i < perguntas; i++)
        {
            scanf("%d %d",&s,&t);
            grafo.graphTraverseBSF(s,t);
        }
        
    }
    
    return 0;
}

//g++ ep5.cpp -o ep5.exe;Get-Content inputep.txt; ./ep5.exe