#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ID 2000000

typedef struct Link
{
    int valor;
    struct Link* next;
}Link;

typedef struct Fila
{
    struct Link *head;
    struct Link *tail;
    int* size;
}Fila;

void create_fila(Fila *fila){
    fila->head = fila->tail = NULL;
    fila->size = 0;
}

void adiciona_fila(Fila *fila, int valor){
    Link * new = (Link*)malloc(sizeof(Link*));
    new->valor = valor;
    new->next = NULL;
    if (new == NULL)
    {
        printf("erro ao alocar memoria");
        exit;
    }
    if (fila->tail)
    {
        fila->tail->next = new;
        fila->tail = new;
    } else {
        fila->head = fila->tail = new;
    }
    fila->size++;
}