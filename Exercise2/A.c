#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char valor;
    struct Node *next;
}Node;

Node* create_node(char element, Node* nextt){
    Node* banana = (Node*)malloc(sizeof(Node));
    banana->valor = element;
    banana->next = nextt;
}

Node* create_head(Node* nextt){
    Node* banana = (Node*)malloc(sizeof(Node));
    banana->next = nextt;
}

typedef struct Llist
{
    Node * head;
    Node * tail;
    int size;
}Llist;

Llist* create_list(){
    Llist* l = (Llist*)malloc(sizeof(Llist));
    l->size = 0;
    l->head = l->tail = create_head(NULL);
    return l;
}

void append(char element, Llist* list){
    list->tail->next = create_node(element,NULL);
    list->tail = list->tail->next;
}

void insert_next_to_head(char element, Llist* list){
    list->head->next = create_node(element,list->head->next);
}

void print_list(Llist* list){
    Node* temp = list->head->next;
    while (temp->next != NULL)
    {
        printf("%c",temp->valor);
        temp = temp->next;
    }
    printf("\n");
}

void clear_list(Llist* list){
    Node* temp = list->head;
    while (temp->next != NULL)
    {
        free(temp);
        temp = temp->next;
    }
    free(list);
}
// void 
// [ ]

int main(){
    char entrada[100001];
    while (scanf(" %s", entrada) != EOF)
    {
    Llist* list = create_list();
    int state = 1;
        for (int i = 0; entrada[i] != '\0' ; i++)
        {
            
            char atual = entrada[i];
            if (atual != '[' && atual != ']')
            {
                if (state == 1)
                {
                    append(atual,list);
                }else if (state == 0){
                    insert_next_to_head(atual,list);
                }
                
            } else
            {
                if (atual == ']')
                {
                    state = 1;
                } else {
                    state = 0;
                }   
            }
        }
        print_list(list);
        // clear_list(list);
    }
    
}

// if(char not especial){
//     if (estado = 0){
//         append()
//     } else {
//         botanocomeco()
//     }
// } else {
//     if (char "["){
//         estado = 0
//     } else {
//         estado = 1
//     }
// }

//gcc A.c -o A.exe ; .\A.exe