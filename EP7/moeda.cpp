#include <bits/stdc++.h>
using namespace std;


int main(){
    int cases,n,curr;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> n;
        if (n == 0)
        {
            cout << "Caso " << i + 1 << ": 0=0" << endl;
            continue;
        }
        int C[n+1], F[n+1];
        list<int> indices;
        for (int a = 0; a < n; a++)
        {
            cin >> curr;
            C[a+1] = curr;
        }
        F[0] = 0;
        F[1] = C[1];
        for (int i = 2; i <= n; i++)
        {
            F[i] = max(C[i] + F[i-2],F[i-1]);
            // if (F[i] == C[i] + F[i-2])
            // {
            //     indicies.push_back(i);
            // }
        }
        int controll = n;
        while (controll > 0) {
            if (F[controll] > F[controll-1]) {
                indices.push_front(C[controll]);
                controll -= 2;
            } else {
                controll -= 1;
            }
        }
        cout << "Caso " << i + 1 << ": ";
        for (auto it = indices.begin(); it != indices.end(); ++it) {
            if (it != indices.begin()) cout << "+";
            cout << *it;
        }
        cout << "=" << F[n] << endl;
    }

    return 0;
}

//g++ moeda.cpp -o moeda.exe ;Get-Content inputmoeda.txt ./moeda.exe