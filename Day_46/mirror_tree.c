// Day 46: Mirror of a Binary Tree
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

void mirror(struct Node *root) {
    if (!root) return;
    struct Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

void inorder(struct Node *root) {
    if (root) { inorder(root->left); printf("%d ", root->data); inorder(root->right); }
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 50); insert(root, 30); insert(root, 70);
    insert(root, 20); insert(root, 40);
    printf("Original Inorder: "); inorder(root); printf("\n");
    mirror(root);
    printf("Mirror Inorder:   "); inorder(root); printf("\n");
    return 0;
}
