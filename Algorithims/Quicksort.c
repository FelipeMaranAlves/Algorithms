#include <stdio.h>

void Quicksort(int a[], int l, int r){
    if (l < r) {
        //s split position
        int s = HoarePartition(a, l, r);
        Quicksort(a, l, s-1);
        Quicksort(a, s+1, r);
    }
}
int HoarePartition(int a[], int l, int r){
    
}



int main(){



    return 0;
}