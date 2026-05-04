// Day 23: Merge Two Sorted Linked Lists
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

struct Node* mergeSorted(struct Node *a, struct Node *b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    struct Node *result = NULL;

    if (a->data <= b->data) {
        result = a;
        result->next = mergeSorted(a->next, b);
    } else {
        result = b;
        result->next = mergeSorted(a, b->next);
    }
    return result;
}

void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    int n1, n2, data;

    printf("Enter number of elements in first sorted list: ");
    scanf("%d", &n1);
    printf("Enter %d sorted elements:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &data);
        insertEnd(&list1, data);
    }

    printf("Enter number of elements in second sorted list: ");
    scanf("%d", &n2);
    printf("Enter %d sorted elements:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &data);
        insertEnd(&list2, data);
    }

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    struct Node *merged = mergeSorted(list1, list2);
    printf("Merged: ");
    printList(merged);

    freeList(merged);
    return 0;
}
