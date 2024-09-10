#include <stdio.h>
// como usar array como ponteiro??



int main(){
    char a[30] = "cuscuz";
    char b[30] = "banana";
    char* lista[2];
    lista[0] = a;
    lista[1] = b;
    printf("%d\n", (a+1));
    printf("%c\n", *(a+1));
    // printf("%s", lista[1]);
    return 0;
}

//gcc teste.c -o teste.exe ; ./teste.exe