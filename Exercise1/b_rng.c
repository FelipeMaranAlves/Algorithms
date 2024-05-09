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
    int pairs = 0;
    int n;
    int k;
    scanf("%d %d", &n, &k);
    int array[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    } //criei a lista em si

    Quicksort(array,0,n-1); //depois disso ta tudo ordenado e funfando
    
    for (int i =0;i<n;i++){
        if (array[i]>k) {
            if(BinarySearchRec(array,0,n-1,(array[i]-k)) != -1){// incrementa se i-k esta contido
                pairs++;
            };
        }
        
    }

    printf("%d", pairs); // saida
    return 0;
}

// gcc b_rng.c -o b_rng.exe ; Get-Content inputb.txt | ./b_rng.exe