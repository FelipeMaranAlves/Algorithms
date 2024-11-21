#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    int key;
    int height;
    struct Node* left;
    struct Node* right;
}Node;

typedef struct BSTree
{
    int nodecount;
    Node* rt;
}BSTree;

int max(int a, int b){
    if (a > b)
    {
        return a;
    }
    return b;
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
    return h(rt->left) - h(rt->right);
}

Node* createnode(int key, int value){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->right = NULL;
    new_node->left = NULL;
    new_node->key = key;
    new_node->value = value;
    new_node->height = 0;
    return new_node;
}

BSTree* create_BSTree(){
    BSTree* new_tree = (BSTree*) malloc(sizeof(BSTree));
    new_tree->nodecount = 0;
    new_tree->rt = NULL;
    return new_tree;
}

Node* rightRotate(Node* rt){
    Node* l = rt->left;
    Node* lr = l->right;
    l->right = rt;
    rt->left = lr;
    rt->height = max(h(rt->left),h(rt->right)) + 1;
    l->height = max(h(l->left),h(l->right)) + 1;
    return l;
}

Node * leftRotate(Node* rt){
    Node* r = rt->right;
    Node* rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = max(h(rt->left),h(rt->right)) + 1;
    r->height = max(h(r->left),h(r->right)) + 1;
    return r;
}

int findhelp(Node* rt, int k, int e){
    if (rt == NULL)
    {
        return 0;
    }
    if (rt->key > k)
    {
        return findhelp(rt->left,k,e);
    } else if (rt->key == k){
        rt->value;
    } else {
        return findhelp(rt->right,k,e);
    }
}

int find(BSTree bst, int k,int e){
    return findhelp(bst.rt,k,e);
}

Node* inserthelp(Node* rt,int k,int e){
    if (rt == NULL)
    {
        return createnode(k,e);
    }
    if (rt->key > k)
    {
        rt->left = inserthelp(rt->left,k,e);
    } else {
        rt->right = inserthelp(rt->right,k,e);
    }
    rt->height = 1 + max(h(rt->left),h(rt->right));//max(h(),h())
    int balance = getBalance(rt);
    if (balance < -1 && k >= rt->right->key)
    {
        return leftRotate(rt);
    }
    if (balance > 1 && k < rt->left->key)
    {
        return rightRotate(rt);
    }
    if (balance > 1 && k>=rt->left->key)
    {
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }
    if (balance < -1 && k < rt->right->key)
    {
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }
    return rt;
}

void insert(BSTree* bst,int k, int e){
    bst->rt = inserthelp(bst->rt,k,e);
    bst->nodecount++;
}

void preorder(Node* rt){
    if (rt != NULL)
    {
        printf("%d\n",rt->key);//do something
        preorder(rt->left);
        preorder(rt->right);
    }
}

void preorderClear(Node* rt){
    if (rt != NULL)
    {
        Node* right = rt->right;
        Node* left = rt->left;
        free(rt);//do something
        preorderClear(left);
        preorderClear(right);
    }
}

void postorderClear(Node* rt){
    if (rt != NULL)
    {
        postorderClear(rt->left);
        postorderClear(rt->right);
        free(rt);//do something
    }
}



int main(){
    int casos, chaves;
    scanf("%d",&casos);
    for (int i = 0; i < casos; i++)
    {
        BSTree* tree = create_BSTree();
        scanf("%d",&chaves);
        for (int i = 0; i < chaves; i++)
        {
            int temp;
            scanf("%d",&temp);
            insert(tree,temp,0);
        }
        preorder(tree->rt);
        postorderClear(tree->rt);
        printf("END\n");
    }
    return 0;
}


//gcc banana.c -o banana.exe ;Get-Content input.txt | ./banana.exe