// Day 41: Binary Tree Insertion and Traversal (Inorder, Preorder, Postorder)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node *root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

void inorder(struct Node *root) {
    if (root) { inorder(root->left); printf("%d ", root->data); inorder(root->right); }
}

void preorder(struct Node *root) {
    if (root) { printf("%d ", root->data); preorder(root->left); preorder(root->right); }
}

void postorder(struct Node *root) {
    if (root) { postorder(root->left); postorder(root->right); printf("%d ", root->data); }
}

int main() {
    struct Node *root = NULL;
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Inorder:   "); inorder(root); printf("\n");
    printf("Preorder:  "); preorder(root); printf("\n");
    printf("Postorder: "); postorder(root); printf("\n");
    return 0;
}
