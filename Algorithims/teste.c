#include <stdio.h>
// como usar array como ponteiro??

void modificadora(int* endarray,int lenght){
    for(int i =0 ;i < lenght-2;i++){
        *endarray = 7;
        endarray++;
    }
}

int main(){
    int array[5] = {1,2,3,4,5};
    int n = sizeof(array)/sizeof(int);
    int * pnti = array;
    for (int i=0; i < n;i++){
        printf("%d ", *pnti);
        pnti++;
    }
    pnti = array;
    printf("%d", array);
    printf("\n");
    modificadora(pnti,n);
    for (int i=0; i < n;i++){
        printf("%d ", *pnti);
        pnti++;
    }
    return 0;
}