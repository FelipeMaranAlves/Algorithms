#include <stdio.h>
#include <stdlib.h>

typedef struct Link
{
    int valor;
    struct Link *next;
} Link;

//to passando o valor do link que eu to criando e o ponteiro de quem esse link vai se ligar
//quando eu quiser criar o primeiro eu passo nextvalue null e qualquer coisa em it
Link* create_link(int element,Link* nextt){
    Link* n = (Link*)malloc(sizeof(Link));
    if (n == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    n->valor = element;
    n->next = nextt;
    return n;
}

Link* create_link_with_no_element(Link *nextt){
    Link* n = (Link*)malloc(sizeof(Link));
    if (n == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    n->next = nextt;
    return n;
}

typedef struct linkedlist
{
    Link *head;
    Link *tail;
    Link *current;
    int count;
}Linkedlist;

Linkedlist* create_list(){
    Linkedlist* l = (Linkedlist*)malloc(sizeof(Linkedlist));
    l->head = l->tail = create_link_with_no_element(NULL);
}

void add_element_to_list(Linkedlist* lista,int value){
    lista->current->next = create_link(value, lista->current->next);
    if (lista->tail == lista->current)
    {
        lista->tail = lista->current->next;
    }
    lista->count++;
}

int main(){
    Link* head = create_link_with_no_element(NULL);
    Link* link1 = create_link(1,head);
    Link* link2 = create_link(2,link1);
    Link* link3 = create_link(3,link2);
    //criei uma lista manualmente com os link
    Link* current = link3;
    while (current->next != NULL)
    {
        printf("esse eh o link com valor: %d\n", current->valor);
        current = current->next;
    }
    free(head);
    free(link1);
    free(link2);
    free(link3);

    Linkedlist *lista1 = create_list();
    // add_element_to_list(lista1, 5);
    printf("%p\n",lista1->head->next);
    printf("%d",lista1->tail->next);
    add_element_to_list(lista1,5);
    printf("%p\n",lista1->head->next);
    printf("%p",lista1->tail->next);
    printf("%p\n",lista1->head->valor);
    printf("%p",lista1->tail->valor);

    return 0;
}
//gcc linkedlist.c -o linkedlist.exe ; .\linkedlist.exe