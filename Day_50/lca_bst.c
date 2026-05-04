// Day 50: Lowest Common Ancestor in BST
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

struct Node* lca(struct Node *root, int n1, int n2) {
    if (!root) return NULL;
    if (root->data > n1 && root->data > n2) return lca(root->left, n1, n2);
    if (root->data < n1 && root->data < n2) return lca(root->right, n1, n2);
    return root;
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 20); insert(root, 10); insert(root, 30);
    insert(root, 5); insert(root, 15); insert(root, 25); insert(root, 35);
    int n1 = 5, n2 = 15;
    struct Node *ancestor = lca(root, n1, n2);
    if (ancestor) printf("LCA of %d and %d is %d\n", n1, n2, ancestor->data);
    n1 = 5; n2 = 35;
    ancestor = lca(root, n1, n2);
    if (ancestor) printf("LCA of %d and %d is %d\n", n1, n2, ancestor->data);
    return 0;
}
