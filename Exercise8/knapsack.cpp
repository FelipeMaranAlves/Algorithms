#include <bits/stdc++.h>
using namespace std;

class knapsack
{
private:
    int** F;
    int n;
    int W;
public:
    //n is the number of objects that are available to be inserted in the sack
    // the matrix has the shape of W lines and n columns
    knapsack(int n,int W) : n(n), W(W) {
        F = new int*[n+1];
        for (int i = 0; i <= n; i++)//0-n
        {
            F[i] = new int[W+1]; //0-W
        }
    }
    ~knapsack(){
        for (int i = 0; i <= n; i++)//0-n
        {
            delete F[i];
        }
        delete F;
    }

    int bestvalue(int* w,int* v){
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0){
                F[i][j] = 0;
            } else if (w[i] <= j) {
                F[i][j] = max(F[i-1][j],v[i]+F[i-1][j-w[i]]);//F[i-1][j] <- o cara de cima, F[i-1][j-w[i]] o cara de cima a esquerda
            }else {
            F[i][j] = F[i-1][j];
        }
        } 
    }
    return F[n][W];
}
};



int main(){
    int W, n, currWt, currVal;
    int* weights;
    int* values;
    cin >> W >> n;
    weights = new int[n+1];
    values = new int[n+1];
    for (int j = 1; j <= n; j++)
    {
        cin >> currWt >> currVal;
        weights[j] = currWt;
        values[j] = currVal;
    }
    knapsack saco(n, W);
    cout << saco.bestvalue(weights, values) << "\n";
    delete[] weights;
    delete[] values;
    return 0;
}
