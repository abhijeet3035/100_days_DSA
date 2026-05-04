// Day 42: Construct Expression Tree and Evaluate
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node {
    char data;
    struct Node *left, *right;
};

struct Node* createNode(char data) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

#define MAX 100
struct Node* stack[MAX];
int top = -1;

void push(struct Node* n) { stack[++top] = n; }
struct Node* pop() { return stack[top--]; }

struct Node* buildExpressionTree(char *postfix) {
    for (int i = 0; postfix[i]; i++) {
        if (isdigit(postfix[i])) {
            push(createNode(postfix[i]));
        } else {
            struct Node *node = createNode(postfix[i]);
            node->right = pop();
            node->left = pop();
            push(node);
        }
    }
    return pop();
}

int evaluate(struct Node *root) {
    if (!root) return 0;
    if (!root->left && !root->right) return root->data - '0';
    int l = evaluate(root->left);
    int r = evaluate(root->right);
    switch (root->data) {
        case '+': return l + r;
        case '-': return l - r;
        case '*': return l * r;
        case '/': return l / r;
    }
    return 0;
}

void inorder(struct Node *root) {
    if (root) {
        if (!isdigit(root->data)) printf("(");
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
        if (!isdigit(root->data)) printf(")");
    }
}

int main() {
    char postfix[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    struct Node *root = buildExpressionTree(postfix);
    printf("Infix: "); inorder(root); printf("\n");
    printf("Result: %d\n", evaluate(root));
    return 0;
}
