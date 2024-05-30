#include <stdio.h>
#include <stdlib.h>

typedef struct Link
{
    int entrada;
    int maximo;
    struct Link *next;
} Link;

Link* create_link(int entrada, int max,Link* nextt){
    Link* n = (Link*)malloc(sizeof(Link));
    if (n == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    n->entrada = entrada;
    n->maximo = max;
    n->next = nextt;
    return n;
}

typedef struct Fila
{
    Link * front;
    Link * rear;
    int size;
}Fila;

Fila * create_fila(){
    Fila * q = (Fila*)malloc(sizeof(Fila));
    q->front = q->rear = create_link(0,0,NULL);
    q->size = 0;
    return q;
}

void entrafila(Fila* q, int entradat,int maximot){
    q->rear->next = create_link(entradat,maximot,NULL);
    q->rear = q->rear->next;
    q->size++;
}

//obs eu preciso chamar os valores do cara que saiu fora da fila
Link* saifila(Fila* q){
    if (q->size == 0)
    {
        printf("erro, n tem ngm pra sair");
        return NULL;
    } 
    Link* it = q->front->next;
    q->front->next = q->front->next->next;
    if (q->front->next == NULL){
        q->rear = q->front;
    }
    q->size--;
    return it;
}

int main(){
    int cases;
    scanf("%d",&cases);
    for (int i = 0; i < cases; i++)
    {
        int students;
        int time = 0;
        scanf("%d",&students);
        Fila* fila_atual = create_fila();
        for (int i = 0; i < students; i++)
        {
            int tempo_entrada, tempo_saida;
            scanf("%d %d", &tempo_entrada, &tempo_saida);
            entrafila(fila_atual, tempo_entrada, tempo_saida);
        }
        for (int i = 0; i < students; i++) // botar tipo um if i == students -1 pra printar melhor o ultimo cara
        {
            // time++;
            Link* aluno_atual = saifila(fila_atual);
            if (time < aluno_atual->entrada)
            {
                time = aluno_atual->entrada;
            }
            if (time <= aluno_atual->maximo)
            {
                printf("%d ",time);
                time++;
            } else{
                printf("0 ");
                // time--;
            }
        }
        printf("\n");
    }
    return 0;
}

//gcc B.c -o B.exe ; Get-Content input.txt | ./B.exe