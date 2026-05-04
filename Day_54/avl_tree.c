// Day 54: AVL Tree Insertion with Rotations
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data, height;
    struct Node *left, *right;
};

int height(struct Node *n) { return n ? n->height : 0; }
int max(int a, int b) { return a > b ? a : b; }
int getBalance(struct Node *n) { return n ? height(n->left) - height(n->right) : 0; }

struct Node* createNode(int data) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data; n->height = 1; n->left = n->right = NULL;
    return n;
}

struct Node* rightRotate(struct Node *y) {
    struct Node *x = y->left, *T2 = x->right;
    x->right = y; y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct Node* leftRotate(struct Node *x) {
    struct Node *y = x->right, *T2 = y->left;
    y->left = x; x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

struct Node* insert(struct Node *node, int data) {
    if (!node) return createNode(data);
    if (data < node->data) node->left = insert(node->left, data);
    else if (data > node->data) node->right = insert(node->right, data);
    else return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data) return rightRotate(node);
    if (balance < -1 && data > node->right->data) return leftRotate(node);
    if (balance > 1 && data > node->left->data) { node->left = leftRotate(node->left); return rightRotate(node); }
    if (balance < -1 && data < node->right->data) { node->right = rightRotate(node->right); return leftRotate(node); }
    return node;
}

void inorder(struct Node *root) {
    if (root) { inorder(root->left); printf("%d ", root->data); inorder(root->right); }
}

int main() {
    struct Node *root = NULL;
    int n, val;
    printf("Enter number of nodes: "); scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d", &val); root = insert(root, val); }
    printf("Inorder: "); inorder(root); printf("\n");
    return 0;
}
