#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

typedef struct dicionario
{
    int banana;
    Linkedlist* a[3]
};


int main(){
    Linkedlist* a[3];
    a[0] = create_list();
    a[1] = create_list();
    a[2] = create_list();
    add_element_to_list(a[0],1);
    movecursornext(a[0]);
    add_element_to_list(a[0],2);
     movecursornext(a[0]);
    add_element_to_list(a[0],3);
     movecursornext(a[0]);
    add_element_to_list(a[1],4);
    add_element_to_list(a[1],5);
    add_element_to_list(a[1],6);
    add_element_to_list(a[2],3);
    print_list_elements(a[0]);
    print_list_elements(a[1]);
    print_list_elements(a[2]);
    return 0;
}

// gcc teste.c -o teste.exe ; ./teste.exe