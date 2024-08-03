#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node* next;

    Node(int a){
        value = a;
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
        if (top == NULL) {return 0;}
        int temp = top->value;
        top = top->next;
        size--;
        return temp;
    }

    int lenght(){
        return size;
    }
};
