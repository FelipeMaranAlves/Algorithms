#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    int value;
    int height;
    struct Node *left;
    struct Node *right;
}Node;  

typedef struct Bst
{
    struct Node* root;
    int node_count;
}Bst;

int max(int a,int b){
    if (a > b)
    {
        return a;
    } else {
        return b;
    }
}

int h(Node* rt){
    if (rt == NULL)
    {
        return -1;
    }
    return rt->height;
}

int getBalance(Node* rt){
    if (rt == NULL)
    {
        return 0;
    }
    return (h(rt->left) - h(rt->right));
}

Node* rightRotate(Node* rt){
    Node* l = rt->left;
    Node* lr = l->right;
    l->right = rt;
    l->left = lr;
    rt->height = max(h(rt->left),h(rt->right)) + 1;
    l->height = max(h(l->left),h(l->right)) +1;
    return l;
}


Node* leftRotate(Node* rt){
    Node* r = rt->right;
    Node* rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = 1 + max(h(rt->left),h(rt->right));
    r->height = 1 + max(h(r->left),h(r->right));
    return r;
}

Node* create_node(int key, int e){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}

Bst* create_BST(){
    Bst* new_tree =  (Bst*)malloc(sizeof(Bst));
    new_tree->root = NULL;
    new_tree->node_count = 0;
    return new_tree;
}

int findehelp(Node* rt, int key){
    if (rt == NULL)
    {
        return -1;
    }
    if (rt->key > key)
    {
        return findehelp(rt->left,key);
    } else if (rt->key == key)
    {
        return rt->value;
    } else {
        return findehelp(rt->right,key);
    }
}

int find(Bst bst, int key){
    return findehelp(bst.root,key);
}

Node* inserthelp(Node* rt,int key,int e){
    if (rt == NULL)
    {
       return rt = create_node(key, e);
    }
    if (rt->key > key)
    {
        rt->left = inserthelp(rt->left,key,e);
    } else{
        rt->right = inserthelp(rt->right,key,e);
    }
    rt->height = 1 + max(h(rt->left),h(rt->right));
    int balance  = getBalance(rt);
    if (balance < -1 && key >= rt->right->key)
    {
        leftRotate(rt);
    }
    if (balance > 1 && key < rt->left->key)
    {
        rightRotate(rt);
    }
    if (balance > 1 && key >= rt->left->key)
    {
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }
    if (balance < -1 && key < rt->right->key)
    {
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }
    return rt;
}

void insert_BST(Bst* bst, int key, int e){
    bst->root = inserthelp(bst->root,key,e);
    bst->node_count++;
}

void preorder(Node* rt){
    if (rt != NULL)
    {
        printf(" %d",rt->key);//do something
        preorder(rt->left);
        preorder(rt->right);
    }
}

void inorder(Node* rt){
    if (rt != NULL)
    {
        inorder(rt->left);
        printf(" %d",rt->key);//do something
        inorder(rt->right);
    }
    
}

void postorder(Node* rt){
    if (rt != NULL)
    {
        postorder(rt->left);
        postorder(rt->right);
        printf(" %d",rt->key);//do something
    }
    
}

void preorderClear(Node* rt ){
    if (rt != NULL)
    {
        Node* right = rt->right;
        Node* left = rt->left;
        free(rt);//do something
        preorder(left);
        preorder(right);
    }
}

int main(){
    return 0;
}

// gcc balancedtree.c -o balancedtree.exe ;./balancedtree.exe