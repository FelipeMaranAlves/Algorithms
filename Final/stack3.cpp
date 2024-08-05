#include <bits/stdc++.h>
using namespace std;
/*
Node
create node
Stack
create stack
push
pop
size
*/
struct Node
{
    int value;
    Node* next;

    Node(int valor){
        value = valor;
        next = NULL;
    }
};

struct Stack
{
    Node* top;
    int size;

    Stack(){
        top = NULL;
        size = 0;
    }

    void push(int new_value){
        Node* new_node = new Node(new_value);
        new_node->next = top;
        top = new_node;
        size++;
    }

    int pop(){
        if (top == NULL) {return;}
        int temp = top->value;
        top = top->next;
        size--;
        return temp;
    }

    int lenght(){
        return size;
    }
};
