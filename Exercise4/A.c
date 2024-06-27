#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int height;
    int size;  // Number of nodes in the subtree rooted at this node
    struct Node* left;
    struct Node* right;
} Node;

int max(int a,int b){
    if (a > b)
    {
        return a;
    } else {
        return b;
    }
}

int height(Node* n) {
    if (n == NULL)
        return 0;
    return n->height;
}

int size(Node* n) {
    if (n == NULL)
        return 0;
    return n->size;
}

Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->height = 1;
    node->size = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    y->size = size(y->left) + size(y->right) + 1;
    x->size = size(x->left) + size(x->right) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    x->size = size(x->left) + size(x->right) + 1;
    y->size = size(y->left) + size(y->right) + 1;

    return y;
}

int getBalance(Node* n) {
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

Node* insert(Node* node, int key) {
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    node->size = 1 + size(node->left) + size(node->right);

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int getRank(Node* root, int key) {
    if (root == NULL)
        return -1;

    if (key < root->key)
        return getRank(root->left, key);
    else if (key > root->key) {
        int rightRank = getRank(root->right, key);
        if (rightRank == -1)
            return -1;
        return 1 + size(root->left) + rightRank;
    } else
        return size(root->left) + 1;
}

int main() {
    Node* root = NULL;
    int Q, type, x;
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &type, &x);
        if (type == 1) {
            root = insert(root, x);
        } else if (type == 2) {
            int rank = getRank(root, x);
            if (rank == -1)
                printf("Data tidak ada\n");
            else
                printf("%d\n", rank);
        }
    }
    return 0;
}

//gcc A.c -o A.exe ;Get-Content inputA.txt | ./A.exe
