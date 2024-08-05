#include <bits/stdc++.h>
using namespace std;

int recBs(int* A,int n,int k,int l, int r){//quando chamar pela primeira vez, se quiser procurar no array todo passar l como 0 e r como n
    int m = l+r/2; //divisao real com floor
    if (l > r) {return 0;}
    if (k == A[m]) {return 1;}
    else if (k > A[m]) { recBs(A,n,k,m+1,r);}   
    else {recBs(A,n,k,l,m-1);}
}
