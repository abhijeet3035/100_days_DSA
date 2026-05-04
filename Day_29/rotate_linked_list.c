// Day 29: Rotate Linked List Right by k Places
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
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

int getLength(struct Node *head) {
    int len = 0;
    while (head) { len++; head = head->next; }
    return len;
}

void rotateRight(struct Node **head, int k) {
    if (*head == NULL || k == 0) return;

    int len = getLength(*head);
    k = k % len;
    if (k == 0) return;

    // Find (len - k)th node
    struct Node *temp = *head;
    for (int i = 1; i < len - k; i++)
        temp = temp->next;

    struct Node *newHead = temp->next;
    temp->next = NULL;

    struct Node *tail = newHead;
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = *head;

    *head = newHead;
}

void printList(struct Node *head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(struct Node *head) {
    struct Node *temp;
    while (head) { temp = head; head = head->next; free(temp); }
}

int main() {
    struct Node *head = NULL;
    int n, data, k;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    printf("Enter k (positions to rotate right): ");
    scanf("%d", &k);

    printf("Original: ");
    printList(head);

    rotateRight(&head, k);

    printf("Rotated:  ");
    printList(head);

    freeList(head);
    return 0;
}
