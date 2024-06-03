#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

//this exercise will have n = 10 therefore we will user m = 15 wich is the smallest m for n/m <= 0.7
typedef struct Dictionary
{
    int m;
    int count;
    struct Linkedlist** hash_table;
} Dictionary;

//devo passar o 15 aqui,
Dictionary* create_dictionary(int size){
    // Hash_function_module(value, size)
    Dictionary* d = (Dictionary*)malloc(sizeof(Linkedlist));
    d->m = size;
    d->count = 0;
    d->hash_table = (Linkedlist**)malloc(size * sizeof(Linkedlist*));
    for (int i = 0; i < size; i++)
    {
        d->hash_table[i] = create_list();
    }
    //d->h = h?? n sei botar a função de hash dentro do meu struct
    return d;
}

int Hash_function_module(int element,int m){
    int key;
    key = element % m;
    if (key < 0)
    {
        key += m;
    }
    return key;
}



int main(){
    int n;
    Dictionary* banana = create_dictionary(10);
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d",&temp);
        add_element_to_list(banana->hash_table[Hash_function_module(i,10)],temp);
    }
    for (int i = 0; i < 10; i++)
    {
        print_list_elements(banana->hash_table[i]);
    }
    
    return 0;
}

//gcc learninghashing.c -o learninghashing.exe ; Get-Content input.txt | ./learninghashing.exe