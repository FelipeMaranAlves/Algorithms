#include <stdio.h>

//recives the memory adress of two variables and switches their values
void swapInt(int* a, int* b){
    int buffer = *a;
    *a = *b;
    *b = buffer;
}

int HoarePartition(int A[], int l, int r){
    int p = A[l];
    int i = l;
    int j = r+1;
    do
    {
        do
        {
            i++;
        } while (!(A[i]>=p||i>=r));
        do
        {
            j--;
        } while (!(A[j]<=p));
        swapInt(&A[i],&A[j]);
    } while (!(i>=j));
    swapInt(&A[i],&A[j]);
    swapInt(&A[l],&A[j]);
    return j;
}


// l and r are the indicies of the subarray you want to order
void Quicksort(int A[], int l, int r){
    if (l < r) {
        //s split position
        int s = HoarePartition(A, l, r);
        Quicksort(A, l, s-1);
        Quicksort(A, s+1, r);
    }
}



int main(){
    int arrayteste[] = {8,3,2,9,7,1,5,4};
    int lenght = sizeof(arrayteste)/sizeof(int);
    Quicksort(arrayteste, 0,lenght-1);
    
    for (int i =0; i < lenght; i++){
        printf("%d", arrayteste[i]);
    }

    return 0;
}

//gcc Quicksort.c -o Quicksort.exe ; ./Quicksort.exe