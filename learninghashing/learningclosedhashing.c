#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <string.h>

int main(){
    char teste[55] = "add ALGORITHMS";
    char action[4];
    char value[51];
    int size = strlen(teste);

    memcpy(action,teste,3);
    memcpy(value,(teste+4),50);

    printf("%s\n",value);
    printf("%s",action);
    return 0;
}