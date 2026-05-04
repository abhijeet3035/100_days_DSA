// Day 39: Priority Queue Implementation
#include <stdio.h>
#define MAX 100

struct PriorityQueue {
    int data[MAX];
    int priority[MAX];
    int size;
};

void init(struct PriorityQueue *pq) { pq->size = 0; }

void enqueue(struct PriorityQueue *pq, int val, int pri) {
    if (pq->size == MAX) { printf("Queue Full!\n"); return; }
    int i = pq->size - 1;
    while (i >= 0 && pq->priority[i] > pri) {
        pq->data[i + 1] = pq->data[i];
        pq->priority[i + 1] = pq->priority[i];
        i--;
    }
    pq->data[i + 1] = val;
    pq->priority[i + 1] = pri;
    pq->size++;
    printf("Enqueued %d with priority %d\n", val, pri);
}

int dequeue(struct PriorityQueue *pq) {
    if (pq->size == 0) { printf("Queue Empty!\n"); return -1; }
    int val = pq->data[0];
    for (int i = 0; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
        pq->priority[i] = pq->priority[i + 1];
    }
    pq->size--;
    return val;
}

void display(struct PriorityQueue *pq) {
    printf("PQ: ");
    for (int i = 0; i < pq->size; i++)
        printf("(%d,p%d) ", pq->data[i], pq->priority[i]);
    printf("\n");
}

int main() {
    struct PriorityQueue pq;
    init(&pq);
    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 3);
    display(&pq);
    printf("Dequeued: %d\n", dequeue(&pq));
    display(&pq);
    return 0;
}
