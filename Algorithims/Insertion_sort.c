#include <stdio.h>

int main() {
    int array[] = {89,45,68,90,29,34,17};
    int n = sizeof(array)/sizeof(int);
    for(int i = 1; i<n;i++){
        int v = array[i];
        int j = i -1;
            while((j>=0)&&(array[j]>v)){
                array[j+1] = array[j];
                j--;
            }
        array[j+1] = v;
    }
        for(int i = 0;i<sizeof(array)/sizeof(int);i++){
        printf("%d ", array[i]);
    }
    return 0;
}