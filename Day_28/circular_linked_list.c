// Day 28: Circular Linked List Creation and Traversal
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode; // Point to itself
        return;
    }
    struct Node *temp = *head;
    while (temp->next != *head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;
}

void traverse(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to %d)\n", head->data);
}

void freeList(struct Node **head) {
    if (*head == NULL) return;
    struct Node *current = (*head)->next;
    while (current != *head) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(*head);
    *head = NULL;
}

int main() {
    struct Node *head = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    printf("Circular Linked List: ");
    traverse(head);

    freeList(&head);
    return 0;
}
