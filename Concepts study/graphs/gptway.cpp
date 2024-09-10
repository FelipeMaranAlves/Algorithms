#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> a;
    list<int> b;
    for (int i = 1; i <= 17; i++)
    {
        a.push_back(i);
    }
    for (int i = 74; i > 68 ; i--)
    {
        b.push_back(i);
    }
    auto it = a.begin();
    advance(it,2);
    a.splice(it,b);
    for (auto it : a)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}

//g++ gptway.cpp -o gptway.exe ; ./gptway.exe