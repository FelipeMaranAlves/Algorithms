#include <bits/stdc++.h>
using namespace std;

int knapBU (int n,int W,int values[],int Weights[]){

    int** matrix = new int*[W+1];
    for (int i = 0; i <= W; ++i) {
        matrix[i] = new int[n+1];
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j==0) {matrix[i][j] = 0;} else {matrix[i][j] = -1;}
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; i <= W; i++)
        {
            if(Weights[i] <= j) {matrix[i][j] = max(matrix[i-1][j],values[i]+matrix[i-1][j-Weights[i]]);
            } else {matrix[i][j] = matrix[i-1][j];}
        }
        
    }
    return matrix[n][W];
}