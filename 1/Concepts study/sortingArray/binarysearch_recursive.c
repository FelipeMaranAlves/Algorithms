#include <stdio.h>


//l and r are indicies (from 0 up to n-1)
int BinarySearchRec(int A[],int l,int r, int key){
    if (r >= l)
    {
        int m = (l+r)/2;
        if (key == A[m])
        {
            return m;
        } else if (key < A[m]){
            return BinarySearchRec(A,l,m-1,key);
        } else {
            return BinarySearchRec(A,m+1,r,key);
        }
    } else
    {
        return -1;
    }
    
}


int main(){
    int testarray[13] = {3,14,27,31,39,42,55,70,74,81,85,93,98};
    printf("%d", BinarySearchRec(testarray,0,12,4));
    return 0;
}

// gcc binarysearch_recursive.c -o binarysearch_recursive.exe ; .\binarysearch_recursive.exe