#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

//the base case for this exercise will have n = 10 therefore we will user m = 15 wich is the smallest m for n/m <= 0.7

typedef struct Dictionary
{
    int m;
    int count;
    struct Linkedlist* hash_table;
    h:
} Dictionary;

Dictionary* create_dictionary(int size,){

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

    return 0;
}