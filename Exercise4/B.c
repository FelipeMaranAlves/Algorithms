#include <stdio.h>
#include <stdlib.h>

enum booleano{
    False = 0,
    True
};

//H has n+1 size H[0] is allways empty
//int n = (sizeof(H)/sizeof(int)) - 1;
void Heapify_BottomUP_Min(int H[],int n){
    for (int i = n/2; i > 0; i--)
    {
        int k = i;
        int v = H[k];
        enum booleano heap = False;
        while (!heap && 2*k <= n){
            int j = 2*k;
            if (j < n)
            {
                if (H[j] > H[j+1])
                {
                    j++;
                }// H[j] is the smallest child
        }
            if (v <= H[j]) //checking if the smallest child is bigger the it's parent
            {
                heap = True;
            } else {
                H[k] = H[j]; // the parent value is updated to the childs value
                k = j; //k recives the child's position
            }
            H[k] = v; //the child recives the parent's old value 
        }
    }
}

//returns the new size
int remove_and_heapify_min(int H[],int n){
    H[1] = H[n-1];
    Heapify_BottomUP_Min(H,n-1);
    return n-1;
}

void printheap(int H[],int n){
        for (int i = 1; i < n; i++)
    {
        printf("%d ",H[i]);
    }
    printf("\n");
}


int main(){
    // int Heap[8] = {-1,2,9,10,6,5,8,7};
    // int n = 8;
    int Heap[5] = {-1,10,40,50,5};
    int n = 5;
    printheap(Heap,n);
    Heapify_BottomUP_Min(Heap,n-1);
    printheap(Heap,n);
    n = remove_and_heapify_min(Heap,n);
    printheap(Heap,n);
    return 0;
}

//gcc bottomup.c -o bottomup.exe ; ./bottomup.exe