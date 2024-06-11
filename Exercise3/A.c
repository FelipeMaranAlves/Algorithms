#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//m == 101

typedef struct Node
{
    char* [16];
};


int hash_function(char* string){
    int value = 0;
    int lenght = strlen(string);
    for (int i = 0; i < lenght; i++)
    {
        value += (string[i]*(i+1));
    }
    value *= 19;
    return value % 101;
}

int main(){

    return 0;
}

//gcc A.c -o A.exe ; ./A.exe