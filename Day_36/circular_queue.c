// Day 36: Circular Queue Implementation
#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

int isFull() { return (rear + 1) % MAX == front; }
int isEmpty() { return front == -1; }

void enqueue(int val) {
    if (isFull()) { printf("Queue Full!\n"); return; }
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = val;
    printf("Enqueued: %d\n", val);
}

int dequeue() {
    if (isEmpty()) { printf("Queue Empty!\n"); return -1; }
    int val = queue[front];
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
    return val;
}

void display() {
    if (isEmpty()) { printf("Queue empty.\n"); return; }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;
    do {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &val); enqueue(val); break;
            case 2: val = dequeue(); if (val != -1) printf("Dequeued: %d\n", val); break;
            case 3: display(); break;
            case 4: break;
        }
    } while (choice != 4);
    return 0;
}
