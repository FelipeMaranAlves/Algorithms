#include <iostream>
#include <vector>
using namespace std;
int sqr(int a){
    return a*a;
}

int main(){
    int n;
    int D = 0;
    vector<int> X,Y;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        X.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        Y.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if ( sqr(X[i]-X[j]) + sqr(Y[i]-Y[j]) > D)
            {
                D = sqr(X[i]-X[j]) + sqr(Y[i]-Y[j]);
            }
        }
    }
    cout << D;
    return 0;
}