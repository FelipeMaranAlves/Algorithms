#include <stdio.h>
#include <stdlib.h>

typedef struct Link
{
    char valor;
    struct Link *next;
} Link;

Link* create_link(char element,Link* nextt){
    Link* n = (Link*)malloc(sizeof(Link));
    if (n == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    n->valor = element;
    n->next = nextt;
    return n;
}


int main(){
    int cases;
    scanf("%d",&cases);
    for (int i = 0; i < cases; i++)
    {
        int students;
        scanf("%d",&students);
        for (int i = 0; i < students; i++)
        {
            int wi,r;

        }
        
    }
    
}