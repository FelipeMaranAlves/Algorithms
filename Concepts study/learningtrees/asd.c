#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    int value;
    struct Node *left;
    struct Node *right;
}Node;

typedef struct Bst
{
    struct Node* root;
    int node_count;
}Bst;


Node* create_node(int key, int e){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = e;
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
    return rt;
}

void insert_BST(Bst* bst, int key, int e){
    bst->root = inserthelp(bst->root,key,e);
    bst->node_count++;
}

void preorder(Node* rt){
    if (rt != NULL)
    {
        printf(" %d",rt->key);
        preorder(rt->left);
        preorder(rt->right);
    }
}

void inorder(Node* rt){
    if (rt != NULL)
    {
        inorder(rt->left);
        printf(" %d",rt->key);
        inorder(rt->right);
    }
    
}

void postorder(Node* rt){
    if (rt != NULL)
    {
        postorder(rt->left);
        postorder(rt->right);
        printf(" %d",rt->key);
    }
    
}



int main(){
    Bst* tree = create_BST();
    int var;
    for (int i = 0; i < 9; i++)
    {
        scanf("%d",&var);
        insert_BST(tree,var,0);
    }
    preorder(tree->root);
    printf("\n");
    inorder(tree->root);
    printf("\n");
    postorder(tree->root);
    return 0;
}

//gcc asd.c -o asd.exe ; ./asd.exe