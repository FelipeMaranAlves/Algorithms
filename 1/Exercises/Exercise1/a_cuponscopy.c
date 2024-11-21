#include <stdio.h>


//recives the memory adress of two variables and switches their values
void swapint(long long int* a, long long int* b){
    long long int buffer = *a;
    *a = *b;
    *b = buffer;
}

int HoarePartition(long long int A[], long long int l, long long int r){
    long long int p = A[l];
    long long int i = l;
    long long int j = r+1;
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
        swapint(&A[i],&A[j]);
    } while (!(i>=j));
    swapint(&A[i],&A[j]);
    swapint(&A[l],&A[j]);
    return j;
}


// l and r are the indicies of the subarray you want to order
void Quicksort(long long int A[], long long int l, long long int r){
    if (l < r) {
        //s split position
        long long int s = HoarePartition(A, l, r);
        Quicksort(A, l, s-1);
        Quicksort(A, s+1, r);
    }
}


int main(){
    long long int nbars;
    long long int ncupons;
    long long int sum = 0;
    

    scanf("%lld", &nbars);
    long long int allbars[nbars];
    for (long long int i = 0; i < nbars; i++){
        scanf("%lld", &allbars[i]);
        sum += allbars[i];
    }
    
    scanf("%lld", &ncupons);
    long long int allcupons[ncupons];
        for (long long int i = 0; i < ncupons; i++){
        scanf("%lld", &allcupons[i]);
    }

    Quicksort(allbars,0,nbars-1);
    
    for (long long int i = 0; i < ncupons; i++)
    {
        printf("%lld\n", sum-allbars[nbars-allcupons[i]]);
    }
    
    return 0;
}

// gcc a_cupons.c -o a_cupons.exe ; Get-Content inputa.txt | .\a_cupons.exe

    //     for (long long int i = 0; i < nbars; i++){ // prlong long intanto pra veriricar se veio certo
    //     prlong long intf("%d ", allbars[i]);
    // }

    // prlong long intf("\n");
    // for (long long int i = 0; i < ncupons; i++){ // prlong long intanto pra veriricar se veio certo
    //     prlong long intf("%d ", allcupons[i]);
    // }