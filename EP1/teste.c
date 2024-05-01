#include <stdio.h>

typedef struct {
    char nome[30];
    int nota;
    int idade;
} Candidato;

void Merge(Candidato A[],int l,int r){ // inscritos,0,numinscritos-1
    Candidato temp[r+l+1];
    for(int i = l; i <= r ; i++){
        temp[i] = A[i];
    }
    int m = (l+r)/2;
    int i1 = l;
    int i2 = m + 1;
    for(int curr = l; curr <= r ;curr++){
        if(i1 == m+1){ //i1 ==m+1
            A[curr] = temp[i2++];
        } else if (i2 > r){
            A[curr] = temp[i1++];
        } else if (temp[i1].idade <= temp[i2].idade){
            A[curr] = temp[i1++];
        } else{
            A[curr] = temp[i2++];
        }
    }
}

void Mergesort(Candidato A[],int l,int r){
    if (l < r){
        int m = (l+r)/2;
        Mergesort(A,l,m);
        Mergesort(A,m+1,r);
        Merge(A,l,r);
    }
}

int main(){ // no momento so pra 1 cargo
    int cargos, num_inscritos, vagas;
    scanf("%d",&cargos);
    for (int i = 0; i < cargos; i++)
    {
        scanf(" %d %d",&num_inscritos, &vagas);
        Candidato inscritos[num_inscritos];
        for (int i = 0;i < num_inscritos;i++){
            scanf(" %s %d %d",inscritos[i].nome, &inscritos[i].nota, &inscritos[i].idade);
        }
        Mergesort(inscritos,0,num_inscritos-1); // <- aqui
        for (int i = 0; i < num_inscritos;i++){
            printf("%s ", inscritos[i].nome);
        }
    }
    
    return 0;
}

// gcc teste.c -o testec.exe ; Get-Content input.txt | ./testec.exe