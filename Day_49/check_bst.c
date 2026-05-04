// Day 49: Check if Binary Tree is BST
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data; n->left = n->right = NULL;
    return n;
}

int isBSTUtil(struct Node *root, int min, int max) {
    if (!root) return 1;
    if (root->data <= min || root->data >= max) return 0;
    return isBSTUtil(root->left, min, root->data) &&
           isBSTUtil(root->right, root->data, max);
}

int isBST(struct Node *root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    // Valid BST
    struct Node *root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    printf("Tree 1 is %s\n", isBST(root) ? "a BST" : "not a BST");

    // Not a BST
    struct Node *root2 = createNode(50);
    root2->left = createNode(60); // violation
    root2->right = createNode(70);
    printf("Tree 2 is %s\n", isBST(root2) ? "a BST" : "not a BST");
    return 0;
}
