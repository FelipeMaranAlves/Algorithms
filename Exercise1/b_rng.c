#include <stdio.h>


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
    int pairs = 0;
    int n;
    int k;
    scanf("%d %d", &n, &k);
    int array[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    Quicksort(array,0,n-1);
    for (int i = 0;i < n;i++){//current = array[i]//pair = array[j]
        int current = array[i];
        int flag = 1;
        while (flag == 1)
        {
            int j = i+1;
            int pair = array[j];
            if (pair-current<k)
            {
                j++;
            } else if(pair-current==k){
                pair++;
            } else{
                flag = 0;
            }
            
        }
        
    }
    printf("%d", pairs);
    return 0;
}