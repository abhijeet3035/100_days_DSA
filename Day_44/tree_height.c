// Day 44: Height of a Binary Tree
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data; n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node *root, int data) {
    if (!root) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

int height(struct Node *root) {
    if (!root) return -1;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

int main() {
    struct Node *root = NULL;
    int n, val;
    printf("Enter number of nodes: "); scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d", &val); root = insert(root, val); }
    printf("Height of the tree: %d\n", height(root));
    return 0;
}
