// Day 27: Intersection Point of Two Linked Lists
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

int getLength(struct Node *head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* getIntersection(struct Node *head1, struct Node *head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = len1 - len2;

    if (diff > 0) {
        while (diff--) head1 = head1->next;
    } else {
        diff = -diff;
        while (diff--) head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) return head1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}

void printList(struct Node *head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Creating two lists that intersect
    // List1: 1 -> 2 -> 3 -> 6 -> 7
    // List2: 4 -> 5 -> 6 -> 7
    // Intersection at node with data 6

    struct Node *common = createNode(6);
    common->next = createNode(7);

    struct Node *head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = common;

    struct Node *head2 = createNode(4);
    head2->next = createNode(5);
    head2->next->next = common;

    printf("List 1: ");
    printList(head1);
    printf("List 2: ");
    printList(head2);

    struct Node *intersection = getIntersection(head1, head2);

    if (intersection)
        printf("Intersection point: %d\n", intersection->data);
    else
        printf("No intersection point.\n");

    return 0;
}
