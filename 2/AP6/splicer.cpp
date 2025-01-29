#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;


int* splicer(int* a1, int sizea1, int* a2, int sizea2, int position){
    if( position < 0 || position > sizea1){return NULL;}
    int* temp = (int*)malloc(sizeof(int)*(sizea1+sizea2));
    // SEM MALLOC int *v = new int[len1+len2];
    int j = 0;
    for (int i = 0;i <= position; i++){ //inseri position elementos de a1
        temp[i] = a1[i];}
    for (int i = position+1;i <= (sizea2+position); i++){ //inseri sizea2 todo
        temp[i] = a2[j];
        j++;}
    j = position+1;
    for (int i = sizea2+position+1;i < sizea1+sizea2; i++){//inserindo o resto de a1 depois de a2
        temp[i] = a1[j];
        j++;}
    return temp;
}

int main(){
    ifstream fin("input");
    ofstream fout("output");
    int s1 = 5;
    int *a = (int*)malloc(sizeof(int) * s1);
    int z[5] = {1,2,3,7,8};
    for (int i = 0; i < 5; i++)
    {a[i] = z[i];}
    int s2 = 3;
    int *b = (int*)malloc(sizeof(int) * s2);
    int z2[3] = {4,5,6};
    for (int i = 0; i < 5; i++)
    {b[i] = z2[i];}
    int* novo = splicer(a,s1,b,s2,0);
    for (int i = 0; i < (s1+s2); i++)
    {
        fout << novo[i] << " ";
    }
    return 0;
}