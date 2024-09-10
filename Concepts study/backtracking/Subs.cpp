#include <bits/stdc++.h>
using namespace std;

// Função para encontrar o número de subconjuntos que somam ao alvo usando backtracking
void countSubsets(vector<int>& arr, int index, int target, int currentSum, int& count) {
    // Se a soma atual for igual ao alvo, incremente o contador
    if (currentSum == target) {
        count++;
        return;
    }

    // Se a soma atual exceder o alvo, retorne
    if (currentSum > target) {
        return;
    }

    // Explore elementos adicionais para formar subconjuntos
    for (int i = index; i < arr.size(); i++) {
        // Inclua o elemento atual e chame a função recursivamente
        countSubsets(arr, i + 1, target, currentSum + arr[i], count);
    }
}

int findSubsetCountThatSumToTarget(vector<int>& arr, int target) {
    // Ordene o array para ajudar na poda
    sort(arr.begin(), arr.end());

    // Variável para armazenar a contagem de subconjuntos que somam ao alvo
    int count = 0;

    // Inicie o processo de backtracking a partir do índice 0
    countSubsets(arr, 0, target, 0, count);

    return count;
}
int main() {
    int cases, n, curr, target;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> n;
        vector<int> set;
        for (int a = 0; a < n; a++)
        {
            cin >> curr;
            set.push_back(curr);
        }
        cin >> target;
        int count = findSubsetCountThatSumToTarget(set,target);
        cout << count << "\n";
    }
    return 0;
}

/* 
input:
2
4
3 5 6 7
15
4
3 5 6 7
17
*/

//g++ Subs.cpp -o Subs.exe ;Get-Content sub.txt | ./Subs.exe