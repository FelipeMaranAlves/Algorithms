#include <stdio.h>
#include <stdlib.h>

typedef struct listarray {
    int maximo;
    int tamanho;
    int posicao;
    int *lista;
} Listarray;

//o inteiro vai ser o tamanho maximo
Listarray* criador(int tam){
Listarray* P = (Listarray*) malloc(sizeof(Listarray));
P->maximo = tam;
P->tamanho = P->posicao = 0;
P->lista = (int *) malloc(tam * sizeof(int));
return P;
}


int main(){
    

    return 0;
}