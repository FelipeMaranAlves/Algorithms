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
    Candidato* lista;
    Candidato candidato1 = create("joaozin",0,6);
    Candidato candidato2 = create("joaozin",10,16);
    // lista[0] = candidato
    // lista[1] = candidato2;
    cout << sizeof(string);
    cout << "banana";
    return 0;
}

// g++ teste.cpp -o teste.exe ; ./teste.exe