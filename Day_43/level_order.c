// Day 43: Level Order Traversal of Binary Tree (BFS)
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
    if (!root) return 0;
    int l = height(root->left), r = height(root->right);
    return (l > r ? l : r) + 1;
}

void printLevel(struct Node *root, int level) {
    if (!root) return;
    if (level == 1) printf("%d ", root->data);
    else { printLevel(root->left, level - 1); printLevel(root->right, level - 1); }
}

void levelOrder(struct Node *root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printLevel(root, i);
        printf("\n");
    }
}

int main() {
    struct Node *root = NULL;
    int n, val;
    printf("Enter number of nodes: "); scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d", &val); root = insert(root, val); }
    printf("Level Order Traversal:\n");
    levelOrder(root);
    return 0;
}
