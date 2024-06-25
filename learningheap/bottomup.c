#include <stdio.h>
#include <stdlib.h>


enum booleano{
    False = 0,
    True
};

//H has n+1 size H[0] is allways empty
//int n = (sizeof(H)/sizeof(int)) - 1;
void HeapifyBottomUP(int H[],int n){
    for (int i = n/2; i > 0; i--)
    {
        int k = i;
        int v = H[k];
        enum booleano heap = False;
        do
        {
            int j = 2*k;
            if (j < n)
            {
                if (H[j] < H[j+1])
                {
                    j++;
                }
            }
            if (v >= H[j])
            {
                heap = True;
            } else {
                H[k] = H[j];
                k = j;
            }
            H[k] = v;
        } while (!heap && 2*k <= n);
    }
}


int main(){
    int Heap[8] = {-1,2,9,10,6,5,8,7};
    int n = 8;
    for (int i = 1; i < n; i++)
    {
        printf("%d ",Heap[i]);
    }
    HeapifyBottomUP(Heap,n-1);
    printf("\n");
    for (int i = 1; i < n; i++)
    {
        printf("%d ",Heap[i]);
    }
    return 0;
}

//gcc bottomup.c -o bottomup.exe ; ./bottomup.exe