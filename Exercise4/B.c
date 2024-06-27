#include <stdio.h>
#include <stdlib.h>

enum booleano{
    False = 0,
    True
};

typedef struct Heapp
{
    int size;
    int* heap;
}Heapp;

//heap already recives an array with size+1, wich the first element is not going to be used
Heapp* create_heap(int* array,int size){
    Heapp* new_heap = (Heapp*) malloc(sizeof(Heapp));
    new_heap->size = size;
    new_heap->heap = (int*)malloc(sizeof(int)*(size+1)); 
    for (int i = 1; i < size; i++)
    {
        new_heap->heap[i] = array[i];
    }
    return new_heap;
}

//H has n+1 size H[0] is allways empty
//int n = (sizeof(H)/sizeof(int)) - 1;
void Heapify_BottomUP_Min(Heapp* Heap){
    int* H = Heap->heap;
    int n = Heap->size;
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

int remove_and_heapify_min(Heapp* Heap){
    int* H = Heap->heap;
    int n = Heap->size;
    int removed = H[1];
    H[1] = H[n-1];
    Heap->size--;
    Heapify_BottomUP_Min(Heap);
    return removed;
}

void printheap(Heapp* Heap){
    int* H = Heap->heap;
    int n = Heap->size;
    for (int i = 1; i < n; i++)
    {
        printf("%d ",H[i]);
    }
    printf("\n");
}


int main(){
    int size;
    int temp = 0;
    int sum = 0;
    scanf("%d",&size);
    int bolle = 1;
    while (bolle) // condicional do loop
    {
        int array[size+1];
        array[0] = -1;
        for (int i = 1; i < size +1; i++) // erro de range
        {
            scanf("%d",&array[i]);
        }
        Heapp* banana = create_heap(array,size +1); //peguei o input e botei no struct certin
        printheap(banana);
        while (banana->size > 2)
        {
            temp += remove_and_heapify_min(banana);
            banana->heap[1] = temp;
            sum += temp;
            Heapify_BottomUP_Min(banana);
        }
        printf("%d\n",sum);
        scanf("%d",&size); // n mecher
        if(size == 0){
            bolle = 0;
        }
    }
    return 0;
}

//gcc B.c -o B.exe;Get-Content inputB.txt | ./B.exe