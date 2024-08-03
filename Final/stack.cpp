#include <bits/stdc++.h>
using namespace std;
/*
lenght
*/
struct Node
{
    int value;
    Node* next;

    Node(int element){
        value = element;
        next = NULL;
    }
};

struct Stack
{
    int size;
    Node* top;

   Stack(){
    top = NULL;
    size = 0;
   }

   void push(int new_item){
    Node* new_node = new Node(new_item);
    new_node->next = top;
    top = new_node;
    size++;
   }

   int pop(){
    if (top == NULL)
    {
        return 0;
    }
    int to_be_returned;
    to_be_returned = top->value;
    top = top->next;
    size--;
    return to_be_returned;
   }

   int lenght(){
    return size;
   }
};


int main(){
    Stack pilha;
    pilha.push(5);
    pilha.push(4);
    pilha.push(3);
    pilha.push(2);
    pilha.push(1);
    while (pilha.lenght() != 0)
    {
        cout << pilha.pop() << " ";
    }
    return 0;
}

