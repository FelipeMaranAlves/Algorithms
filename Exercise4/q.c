#include <stdio.h>
#include <stdlib.h>

enum booleano {
    False = 0,
    True
};

typedef struct Heapp {
    int size;
    int* heap;
} Heapp;

//heap already receives an array with size+1, with the first element not going to be used
Heapp* create_heap(int* array, int size) {
    Heapp* new_heap = (Heapp*) malloc(sizeof(Heapp));
    new_heap->size = size;
    new_heap->heap = (int*)malloc(sizeof(int) * (size + 1)); 
    for (int i = 1; i <= size; i++) {
        new_heap->heap[i] = array[i];
    }
    return new_heap;
}

//H has n+1 size H[0] is always empty
void Heapify_BottomUP_Min(Heapp* Heap) {
    int* H = Heap->heap;
    int n = Heap->size;
    for (int i = n / 2; i > 0; i--) {
        int k = i;
        int v = H[k];
        enum booleano heap = False;
        while (!heap && 2 * k <= n) {
            int j = 2 * k;
            if (j < n) {
                if (H[j] > H[j + 1]) {
                    j++;
                }
            }
            if (v <= H[j]) {
                heap = True;
            } else {
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
}

int remove_and_heapify_min(Heapp* Heap) {
    int* H = Heap->heap;
    int n = Heap->size;
    int removed = H[1];
    H[1] = H[n];
    Heap->size--;
    Heapify_BottomUP_Min(Heap);
    return removed;
}

void printheap(Heapp* Heap) {
    int* H = Heap->heap;
    int n = Heap->size;
    for (int i = 1; i <= n; i++) {
        printf("%d ", H[i]);
    }
    printf("\n");
}

int main() {
    int size, temp;
    scanf("%d", &size);

    while (size != 0) {
        int array[size + 1];
        array[0] = -1;
        for (int i = 1; i <= size; i++) {
            scanf("%d", &array[i]);
        }

        Heapp* banana = create_heap(array, size);
        Heapify_BottomUP_Min(banana);

        int sum = 0;
        while (banana->size > 1) {
            int min1 = remove_and_heapify_min(banana);
            int min2 = remove_and_heapify_min(banana);
            temp = min1 + min2;
            sum += temp;
            banana->heap[++banana->size] = temp;
            Heapify_BottomUP_Min(banana);
        }

        printf("%d\n", sum);

        scanf("%d", &size);
    }
    return 0;
}
// gcc q.c -o q.exe ; Get-Content inputB.txt | ./q.exe
