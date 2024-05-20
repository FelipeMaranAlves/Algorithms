#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int valor;
    Link* next; 
}Link;

Link* criador_link(int it,Link *proximovalor){
    Link *n;
    n->valor = it;
    n->next = proximovalor;
    return n;
}

Link* criador_primeiro_link(Link *proximovalor){
    Link *n;
    n->next = proximovalor;
    return n;
}

typedef struct fila
{
    Link *head;
    Link *fundo;
    int tamanho;
}Fila;

Fila* criar_fila(){
    Fila *q;
    q->head = q->fundo = criador_primeiro_link(NULL);
    q->tamanho = 0;
    return q;
}

Fila* entra_fila(Fila *q, int it){
    q->fundo->next = criador_link(it,NULL);
    q->fundo = q->fundo->next;
    q->tamanho++;
    return q;
}

Fila* sai_fila(Fila *q){
    if (q->tamanho != 0)
    {
        int it = q->head->next->valor;
        q->head->next = q->head->next->next; //isso pode?
        if (q->head->next = NULL)
        {
            q->fundo = q->head;
            q->tamanho--;
        }
        return q;
    }
    
}

//fazer o sizeof de uma fila
//percorrer uma fila e printar seus elementos
int main(){
    Fila* questoes = criar_fila();
    char entrada[5];
    while (entrada != "end")
    {
        int resolvidas;
        scanf(" %s",entrada);
        if (entrada == "add"){
            int num;
            
            scanf("%d",&num);
            questoes = entra_fila(questoes,num);
        } else if (entrada == "solve"){
            questoes = sai_fila(questoes);
            resolvidas++;
        } else if (entrada == "print"){
            Fila *atual = questoes;
            Link *cara = atual->head;
            while (cara->next != NULL)
            {
             printf("%d ",cara->next->valor);
             cara = cara->next;
            }
            printf("\n");
        } else if (entrada == "stats"){
            printf("%d %d\n",resolvidas,questoes->tamanho);
        }
    }
    return 0;
}