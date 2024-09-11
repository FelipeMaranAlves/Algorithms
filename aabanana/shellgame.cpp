
#include <vector>
#include <fstream>
using namespace std;
// the game has a constant set of shells so we can simulate in n*3 time

int main(){
    ifstream fin("shell.in");
    ofstream fout("shell.out");

    int Nswaps, a, b, g;
    int best_guess = 0;
    fin >> Nswaps;
    vector<int> Vswaps;

    for(int i = 0; i < Nswaps; i++){
        fin >> a >> b >> g;
        Vswaps.push_back(a); Vswaps.push_back(b); Vswaps.push_back(g);
    }

    for (int i = 0; i < 3; i++){
        int correct_position = i+1;
        int total_guesses = 0;

        for (int j = 0; j < Nswaps; j++){
            if (correct_position == Vswaps[j*3]){
                correct_position = Vswaps[(j*3)+1];
            } else if (correct_position == Vswaps[(j*3)+1]) {
                correct_position = Vswaps[j*3];
            }
            if (correct_position == Vswaps[(j*3)+2]){
                total_guesses += 1;
            }
        }
        if (best_guess < total_guesses){ best_guess = total_guesses;}
    }
    fout << best_guess;
    return 0;
}