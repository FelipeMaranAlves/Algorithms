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
    Candidato lista[2];
    Candidato candidato1 = create("Aqueriano",0,6);
    Candidato candidato2 = create("Nato",10,16);
    lista[0] = candidato1;
    lista[1] = candidato2;
    for (int i = 0;i<2;i++){
        cout << lista[i].nome;
    }
    return 0;
}

// g++ teste.cpp -o teste.exe ; ./teste.exe