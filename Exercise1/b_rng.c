#include <stdio.h>
#include <math.h>
int abs(int a){
    return sqrt(a*a);
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
    for (int i = 0;i < n;i++){
        //current = array[i]
        int current = array[i];
        for (int j = i+1; j < n; j++){
            //pair = array[j]
            int pair = array[j];
            if (abs(pair-current)==k){
                pairs++;
            }
        }
    }
    printf("%d", pairs);
    return 0;
}