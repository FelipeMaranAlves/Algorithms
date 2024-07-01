#include <bits/stdc++.h>
using namespace std;

#define UNVISITED 0
#define VISITED 1

/*
to be brave is to act inspite of fear
*/

typedef struct vertex
{
    //1 is visited 0 is not
    int visited;
    // aka name
    int value; 
};

//remember the matrix itself keeps the weights assuming 0 is the absense of an edge
//for now all vertexes are given a value equal to it's position on the mark array 
class MatrixGraph
{
private:
    int** matrix;
    int numEdge;
    vertex* Mark;
    int numVertex;

public:
    MatrixGraph(int n){
        numVertex = n;
        numEdge = 0;
        matrix = (int**)malloc(n*sizeof(int*));
        Mark = (vertex*)malloc(sizeof(vertex)*n);
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
            Mark[i].visited = UNVISITED;
            Mark[i].value = i; //for now all verticies have the same value as it's position on the array Mark
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
    //pointless just use numvertex
    int n(){
        return numVertex;
    }
    //pointless just use numEdge
    int e(){
        return numEdge;
    }

    //return first neightbor of "v"
    int first(int v){
        for (int i = 0; i < numVertex; i++)
        {
            if (matrix[v][i] != 0)
            {
                return i;
            }
        }
        return numVertex; // return n if none
    }
    //Return v’s next neighbor after w
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
        matrix[i][j];
    }
};


/*
   4 5 6
4  0 1 0
5  0 0 1
6  1 0 0

[4,5,6]
*/
int main(){
    MatrixGraph grafobanana(3);
    return 0;
}