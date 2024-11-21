#include <bits/stdc++.h>
using namespace std;

int knapBU(int n,int W,int value_of[],int weigh_of[]){
    int** F = new int*[W+1];
    for (int i = 0; i <= W; ++i) {
        F[i] = new int[n+1];
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j==0) {F[i][j] = 0;} else {F[i][j] = -1;}
        }
    }
    for (int i = 1; i <=n;i++){
        for (int j = 1; j < W;j++){
            int &current = F[i][j];
            int notInsert = F[i-1][j];
            int Insert = value_of[i] + F[i-1][j-weigh_of[i]];
            if (weigh_of[i] <= j) {current = max(notInsert,Insert);
            } else {current = notInsert;}
        }
    }
    return F[n][W];
}   