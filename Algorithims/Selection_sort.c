//forca bruta A[0->n-1]
#include <stdio.h>

int main(){
    int array[] = {89,45,68,90,29,34,17};

    int n = sizeof(array)/sizeof(int);
    for (int i = 0; i < n-1;i++){
        int min = i;
        for (int j = i+1;j < n;j++){
            if (array[j] < array[min]){
                min = j;
            }

        }
        //swap array[min] array[i]
        int buffer;
        buffer = array[i];
        array[i] = array[min];
        array[min] = buffer;
    }
    for(int i = 0;i<sizeof(array)/sizeof(int);i++){
        printf("%d ", array[i]);
    }
    return 0;
}