#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//desisti, n faltava mto mas cansei, apra arvores binárias!!
//A política de resolução de colisões é baseada em pseudo-random probing, conforme p(k,i) = perm[i-1], onde perm é o array de permutações.

int hash_function(int key, int mod) {
    int temp = (int) floor((((double) key) / ((double) mod)));
    return (key - (mod * temp));
}

typedef struct elemento
{
    int key;
    int value;
    int ocupied;
}elemento;


typedef struct Dic
{
    int* permutation_array;
    int m;
    int count;
    elemento* hash_table;
}Dic;

Dic* initialize(int m,int* permutation_arrayy){
    Dic* dic = (Dic*)malloc(sizeof(Dic));
    dic->permutation_array = permutation_arrayy;
    dic->m = m;
    dic->count = 0;
    dic->hash_table = (elemento*)malloc(m*sizeof(elemento));
    for (int i = 0; i < m; i++)
    {
        dic->hash_table[i].ocupied = 0;
        dic->hash_table[i].value = -69;
    }
    return dic;
}

void insert_in_dic(Dic* dictionary, int element
){
    int index = hash_function(element,dictionary->m);
    int tries = 0;
    elemento atual = dictionary->hash_table[index];  
    if (dictionary->count < dictionary->m)
    {
        while (atual.ocupied == 0 && atual.value != element)
        {
            int probe = dictionary->permutation_array[tries % (dictionary->m-1)];
            index = (index + probe) % dictionary->m;
            tries++;
        }
        dictionary->hash_table[index].value = element;
    }
    
    // if (dictionary->hash_table[hash_function(element,dictionary->m)]->ocupied == 0)
    // {
    //     dictionary->hash_table[hash_function(element,dictionary->m)]->value = element;
    //     dictionary->hash_table[hash_function(element,dictionary->m)]->key = hash_function(element,dictionary->m);
    //     dictionary->hash_table[hash_function(element,dictionary->m)]->ocupied = 1;
    // } else if (dictionary->hash_table[hash_function(element,dictionary->m)]->ocupied == 1){
    //     int temp_new_key;
    //     temp_new_key = 
    // }
    
    // dictionary->hash_table[]; // isso nas primeira inserções
    // hash_function(element,dictionary->m);
}







int main(){ //add -10 -5
    int m;
    scanf("%d",&m);
    int* perm = (int*)malloc((m-1) * sizeof(int));
    for (int i = 0; i < m-1; i++)
    {
        int temp;
        scanf("%d",&temp);
        perm[i] = temp;
    }
    Dic* banana = initialize(m,perm);
    int n_comandos;
    scanf("%d",&n_comandos);
    for (int i = 0; i < n_comandos; i++)
    {
        char entrada[5];
        int valor1,valor2;
        scanf("%s",entrada);
        if (strcmp(entrada,"add") == 0)
        {
            scanf("%d %d",&valor1,&valor2);
        } else if(strcmp(entrada,"find") == 0) {
            scanf("%d",&valor1);
        }
    }
    for (int i = 0; i < m; i++)
    {
        printf("%d ", banana->hash_table[i].value);
    }
    return 0;
    
}
    // for (int i = 0; i < m-1; i++)
    // {
    //     printf("%d ",perm[i]);
    // }
//gcc eba.c -o eba.exe ; Get-Content input.txt | ./eba.exe

// x
// 1 2 3 4
// 0 1 2 3