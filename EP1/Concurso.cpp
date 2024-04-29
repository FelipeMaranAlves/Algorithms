#include <iostream>
#include <string>
using namespace std;
//usar o merge por ser estavel, pra fazer as ordens


// tem nome nota e eidade
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
//32 4 4 (40)
//adaptar isso pra struct de algum jeito
void Merge(Candidato* A,int l,int r){
    Candidato temporary[l+r];
    int i1;
    int i2;
    int m;
    for (int i = l;i <= r;i++){
        temporary[i] = A[i];
        m = (l+r)/2;
        i1 = l;
        i2 = m+1;
    }
    for (int current = l; current <= r;current++)
    {
        if (i1 == m+1)
        {
            A[current] = temporary[i2++];
        } else if (i2 > r){
            A[current] = temporary[i1++];
        } else if (temporary[i1].nota <= temporary[i2].nota){
            A[current] = temporary[i1++];
        } else {
            A[current] = temporary[i2++];
        }
        
    }
    
}

// vou ter que mudar depois pra ser com um STRUCT nao ARRAY
void Mergesort(int* A,int l,int r){
    if (l < r){
        int m  = l+r/2;
        Mergesort(A,l,m);
        Mergesort(A,m+1,r);
        Merge(A,l,r);
    }



}

int main(){
    int cargos;
    cin >> cargos;
    for (int i=0;i<cargos;i++){ // loop do numero de cargos
        int inscritos;
        int vagas;
        cin >> inscritos >> vagas;
        // falta fazer um if para qunado vagas > candidatos
        for (int j =0;j<inscritos;j++){  // loop de cada cargo (candidatos)
            string sbuffer;
            int nbuffer;
            int ibuffer;
            cin >> sbuffer >> nbuffer >> ibuffer;
            create(sbuffer,nbuffer,ibuffer);
        }
    }
    return 0;
}

// gcc Concurso.cpp -o Concurso.exe ; ./Concurso.exe