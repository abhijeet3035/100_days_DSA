// Day 66: Hashing with Chaining (Separate Chaining)
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct Node {
    int data;
    struct Node *next;
};

struct Node* hashTable[SIZE] = {NULL};

int hashFunc(int key) { return key % SIZE; }

void insert(int key) {
    int idx = hashFunc(key);
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = key; n->next = hashTable[idx];
    hashTable[idx] = n;
    printf("Inserted %d at index %d\n", key, idx);
}

int search(int key) {
    int idx = hashFunc(key);
    struct Node *temp = hashTable[idx];
    while (temp) { if (temp->data == key) return 1; temp = temp->next; }
    return 0;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("[%d]: ", i);
        struct Node *temp = hashTable[i];
        while (temp) { printf("%d -> ", temp->data); temp = temp->next; }
        printf("NULL\n");
    }
}

int main() {
    insert(10); insert(20); insert(15); insert(25); insert(30); insert(5);
    display();
    printf("Search 15: %s\n", search(15) ? "Found" : "Not Found");
    printf("Search 99: %s\n", search(99) ? "Found" : "Not Found");
    return 0;
}
