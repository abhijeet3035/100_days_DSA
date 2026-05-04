// Day 48: Check if Two Trees are Identical
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

int areIdentical(struct Node *a, struct Node *b) {
    if (!a && !b) return 1;
    if (!a || !b) return 0;
    return (a->data == b->data) &&
           areIdentical(a->left, b->left) &&
           areIdentical(a->right, b->right);
}

int main() {
    struct Node *tree1 = NULL, *tree2 = NULL;
    tree1 = insert(tree1, 50); insert(tree1, 30); insert(tree1, 70);
    tree2 = insert(tree2, 50); insert(tree2, 30); insert(tree2, 70);
    printf("Trees are %s\n", areIdentical(tree1, tree2) ? "identical" : "not identical");
    insert(tree2, 100);
    printf("After modification: Trees are %s\n", areIdentical(tree1, tree2) ? "identical" : "not identical");
    return 0;
}
