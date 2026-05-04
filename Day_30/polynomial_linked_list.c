// Day 30: Polynomial Representation using Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node **head, int coeff, int exp) {
    struct Node *newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void displayPoly(struct Node *head) {
    int first = 1;
    while (head != NULL) {
        if (!first && head->coeff > 0) printf("+ ");
        printf("%dx^%d ", head->coeff, head->exp);
        head = head->next;
        first = 0;
    }
    printf("\n");
}

struct Node* addPoly(struct Node *p1, struct Node *p2) {
    struct Node *result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insertEnd(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            insertEnd(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0)
                insertEnd(&result, sum, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insertEnd(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertEnd(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

void freeList(struct Node *head) {
    struct Node *temp;
    while (head) { temp = head; head = head->next; free(temp); }
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL;
    int n, coeff, exp;

    printf("Enter number of terms in polynomial 1: ");
    scanf("%d", &n);
    printf("Enter coefficient and exponent for each term:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertEnd(&poly1, coeff, exp);
    }

    printf("Enter number of terms in polynomial 2: ");
    scanf("%d", &n);
    printf("Enter coefficient and exponent for each term:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertEnd(&poly2, coeff, exp);
    }

    printf("Polynomial 1: ");
    displayPoly(poly1);
    printf("Polynomial 2: ");
    displayPoly(poly2);

    struct Node *sum = addPoly(poly1, poly2);
    printf("Sum:          ");
    displayPoly(sum);

    freeList(poly1);
    freeList(poly2);
    freeList(sum);
    return 0;
}
