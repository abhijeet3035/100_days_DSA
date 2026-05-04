// Day 47: Count Leaf Nodes in Binary Tree
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

int countLeaves(struct Node *root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    struct Node *root = NULL;
    int n, val;
    printf("Enter number of nodes: "); scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d", &val); root = insert(root, val); }
    printf("Number of leaf nodes: %d\n", countLeaves(root));
    return 0;
}
