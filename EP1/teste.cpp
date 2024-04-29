#include <iostream>
#include <string>
using namespace std;

struct Candidato
{
    string nome;
    int nota;
    int idade;
};

Candidato create(string nome,int nota,int idade){
    Candidato ponteiro;
    ponteiro.nome = nome;
    ponteiro.nota = nota;
    ponteiro.idade = idade;
    return ponteiro;
}

int main(){
    Candidato banana = create("joaozin",0,6);
    cout << sizeof(int);
    return 0;
}

// gpp teste.cpp -o teste.exe ; ./teste.exe