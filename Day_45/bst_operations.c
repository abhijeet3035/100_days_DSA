// Day 45: Binary Search Tree - Search, Insert, Delete
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
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

struct Node* search(struct Node *root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

struct Node* minValueNode(struct Node *node) {
    while (node && node->left) node = node->left;
    return node;
}

struct Node* deleteNode(struct Node *root, int key) {
    if (!root) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) { struct Node *t = root->right; free(root); return t; }
        if (!root->right) { struct Node *t = root->left; free(root); return t; }
        struct Node *t = minValueNode(root->right);
        root->data = t->data;
        root->right = deleteNode(root->right, t->data);
    }
    return root;
}

void inorder(struct Node *root) {
    if (root) { inorder(root->left); printf("%d ", root->data); inorder(root->right); }
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 50); insert(root, 30); insert(root, 70);
    insert(root, 20); insert(root, 40); insert(root, 60); insert(root, 80);
    printf("Inorder: "); inorder(root); printf("\n");
    printf("Search 40: %s\n", search(root, 40) ? "Found" : "Not Found");
    root = deleteNode(root, 30);
    printf("After deleting 30: "); inorder(root); printf("\n");
    return 0;
}
