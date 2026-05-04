// Day 37: Double Ended Queue (Deque) Implementation
#include <stdio.h>
#define MAX 100

int deque[MAX], front = -1, rear = -1;

int isEmpty() { return front == -1; }
int isFull() { return (front == 0 && rear == MAX - 1) || (front == rear + 1); }

void insertFront(int val) {
    if (isFull()) { printf("Deque Full!\n"); return; }
    if (front == -1) { front = rear = 0; }
    else if (front == 0) front = MAX - 1;
    else front--;
    deque[front] = val;
    printf("Inserted %d at front\n", val);
}

void insertRear(int val) {
    if (isFull()) { printf("Deque Full!\n"); return; }
    if (front == -1) { front = rear = 0; }
    else if (rear == MAX - 1) rear = 0;
    else rear++;
    deque[rear] = val;
    printf("Inserted %d at rear\n", val);
}

int deleteFront() {
    if (isEmpty()) { printf("Deque Empty!\n"); return -1; }
    int val = deque[front];
    if (front == rear) front = rear = -1;
    else if (front == MAX - 1) front = 0;
    else front++;
    return val;
}

int deleteRear() {
    if (isEmpty()) { printf("Deque Empty!\n"); return -1; }
    int val = deque[rear];
    if (front == rear) front = rear = -1;
    else if (rear == 0) rear = MAX - 1;
    else rear--;
    return val;
}

int main() {
    insertRear(10); insertRear(20); insertFront(5);
    printf("Deleted front: %d\n", deleteFront());
    printf("Deleted rear: %d\n", deleteRear());
    return 0;
}
