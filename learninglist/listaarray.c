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

void inserir(Listarray lista,int it){
    if (lista.tamanho >= lista.maximo)
    {
        printf("opa meu patrao, nao da pra inserir cm ela cheia"); // n sei fazer dar erro
    } else {
        int i = lista.tamanho;
        while (i > lista.posicao)
        {
            lista.lista[i] = lista.lista[i-1]; // obs "lista" eh o objeto abstrato que contem a lista em si e algumas informacoes sobre ela, por isso o lista.lista
            i--;
        }
    }
    lista.lista[lista.posicao] = it;
    lista.tamanho++;
}

void moverinicio(Listarray lista){
    lista.posicao = 0;
}

void moverfim(Listarray lista){
    lista.posicao = lista.tamanho;
}

void anterior(Listarray lista){
    if (lista.posicao != 0)
    {
        lista.posicao--;
    }
}

void proximo(Listarray lista){
    if (lista.posicao < lista.tamanho)
    {
        lista.posicao++;
    }
}

int remover(Listarray lista){
    if (lista.posicao < 0 || lista.posicao >= lista.tamanho)
    {
        return NULL;
    }
    int it = lista.lista[lista.posicao];
    int i = lista.posicao;
    while (i < lista.tamanho-1)
    {
        lista.lista[i] = lista.lista[i+1];
        i++;
    }
    lista.tamanho--;
    return it;
}

int main(){
    return 0;
}