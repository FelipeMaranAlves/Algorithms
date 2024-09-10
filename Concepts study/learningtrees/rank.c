#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    int value;
    int height;
    int size; // Novo campo para armazenar o tamanho da subárvore
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Bst
{
    struct Node* root;
    int node_count;
} Bst;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int h(Node* rt) {
    return (rt == NULL) ? -1 : rt->height;
}

int size(Node* rt) {
    return (rt == NULL) ? 0 : rt->size;
}

int getBalance(Node* rt) {
    return (rt == NULL) ? 0 : h(rt->left) - h(rt->right);
}

Node* rightRotate(Node* rt) {
    Node* l = rt->left;
    Node* lr = l->right;
    l->right = rt;
    rt->left = lr;

    rt->height = max(h(rt->left), h(rt->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;

    rt->size = size(rt->left) + size(rt->right) + 1;
    l->size = size(l->left) + size(l->right) + 1;

    return l;
}

Node* leftRotate(Node* rt) {
    Node* r = rt->right;
    Node* rl = r->left;
    r->left = rt;
    rt->right = rl;

    rt->height = max(h(rt->left), h(rt->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;

    rt->size = size(rt->left) + size(rt->right) + 1;
    r->size = size(r->left) + size(r->right) + 1;

    return r;
}

Node* create_node(int key, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->height = 0;
    new_node->size = 1; // Inicializando o tamanho da subárvore
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Bst* create_BST() {
    Bst* new_tree = (Bst*)malloc(sizeof(Bst));
    new_tree->root = NULL;
    new_tree->node_count = 0;
    return new_tree;
}

int findehelp(Node* rt, int key) {
    if (rt == NULL) {
        return -1;
    }
    if (rt->key > key) {
        return findehelp(rt->left, key);
    } else if (rt->key == key) {
        return rt->value;
    } else {
        return findehelp(rt->right, key);
    }
}

int find(Bst bst, int key) {
    return findehelp(bst.root, key);
}

Node* inserthelp(Node* rt, int key, int value) {
    if (rt == NULL) {
        return create_node(key, value);
    }
    if (rt->key > key) {
        rt->left = inserthelp(rt->left, key, value);
    } else {
        rt->right = inserthelp(rt->right, key, value);
    }

    rt->height = 1 + max(h(rt->left), h(rt->right));
    rt->size = size(rt->left) + size(rt->right) + 1;

    int balance = getBalance(rt);

    if (balance > 1 && key < rt->left->key) {
        return rightRotate(rt);
    }
    if (balance < -1 && key > rt->right->key) {
        return leftRotate(rt);
    }
    if (balance > 1 && key > rt->left->key) {
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }
    if (balance < -1 && key < rt->right->key) {
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }

    return rt;
}

void insert(Bst* bst, int key, int value) {
    bst->root = inserthelp(bst->root, key, value);
    bst->node_count++;
}

// Função para obter o rank de um nó com uma dada chave
int getRank(Node* rt, int key) {
    if (rt == NULL) {
        return -1; // chave não encontrada
    }
    if (key < rt->key) {
        return getRank(rt->left, key);
    } else if (key > rt->key) {
        int left_size = size(rt->left);
        int right_rank = getRank(rt->right, key);
        if (right_rank == -1) {
            return -1; // chave não encontrada
        }
        return left_size + 1 + right_rank;
    } else {
        return size(rt->left);
    }
}

int rank(Bst bst, int key) {
    return getRank(bst.root, key);
}
