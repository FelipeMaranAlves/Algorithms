// linkedlist.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


//to passando o valor do link que eu to criando e o ponteiro de quem esse link vai se ligar
//quando eu quiser criar o primeiro eu passo nextvalue null e qualquer coisa em it
typedef struct Link
{
    int valor;
    struct Link *next;
} Link;

typedef struct linkedlist
{
    Link *head;
    Link *tail;
    Link *current;
    int count;
}Linkedlist;

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

Linkedlist* create_list(){
    Linkedlist* l = (Linkedlist*)malloc(sizeof(Linkedlist));
    l->head = l->tail = l->current = create_link(-69,NULL);
    l->count = 0;
    return l;
}

void move_cursor_start(Linkedlist* lista){
    lista->current = lista->head;
}

void move_cursor_tail(Linkedlist* lista){
    lista->current = lista->tail;
}

void movecursornext(Linkedlist* lista){
    if (lista->current != lista->tail)
    {
        lista->current = lista->current->next; 
    }
    
}

void movecursorprevius(Linkedlist* lista){ // acho que to fazendo bem ineficiente já que não é duplamente ligado, mas enfim
    if (lista->current != lista->head)
    {
        Link * temp = lista->head;
        while (temp->next != lista->current)
        {
            temp = temp->next;
        }
        lista->current = temp;
    }
}

void add_element_to_list(Linkedlist* lista,int value){
    lista->current->next = create_link(value, lista->current->next);
    if (lista->tail == lista->current)
    {
        lista->tail = lista->current->next;
    }
    lista->count++;
}

int remove_element(Linkedlist* lista){
    if (lista->current->next == NULL)
    {
        return 0;
    }
    int it = lista->current->next->valor;
    if (lista->tail == lista->current->next)
    {
        lista->tail = lista->current;
    }
    lista->current->next = lista->current->next->next;
    lista->count--;
    return it;
}

void print_list_elements(Linkedlist* lista){
    Link  * temporario = lista->head->next;
    while (temporario != NULL)
    {
        printf("%d ",temporario->valor);
        temporario = temporario->next;
    }
    printf("\n");
}


#endif