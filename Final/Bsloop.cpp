#include <bits/stdc++.h>
using namespace std;

int BSlp(int* A,int n,int k){
    int l = 0;
    int r = n;
    int m;
    while (l <= r)
    {
        m = l+r/2;//cm floor
        if (k == A[m])
        {
            return 1;
        } else if (k < A[m]){
            r = m-1;
        } else {
            l = m+1;
        }
    }
    return 0;
}