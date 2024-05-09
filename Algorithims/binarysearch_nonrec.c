#include <stdio.h>
// n is the size of the array
int BinarySearch(int A[],int key,int n){
    // int n = sizeof(A); uma merda
    // int n = (&A)[0] - A; n sei como funciona essa por
    int l = 0;
    int r = n-1;
    int m;
    do
    {
        m = l+r/2;
        if (key == A[m]) {
            printf("banana1\nl:%d m:%d r:%d\n",l,m,r);
            return m;
        } else if (key < A[m]) {
            r = m-1;
            printf("banana2\nl:%d m:%d r:%d\n",l,m,r);
        } else {
            l = m+1;
            printf("banana3\nl:%d m:%d r:%d\n",l,m,r);
        }
    } while (r>l);
    return -1;
}

int main(){
    int testarray[13] = {3,14,27,31,39,42,55,70,74,81,85,93,98};
    printf("%d", BinarySearch(testarray,31,sizeof(testarray)/sizeof(int)));
    return 0;
}