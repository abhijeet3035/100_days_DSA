// Day 35: Queue Implementation using Array
#include <stdio.h>
#define MAX 100

struct Queue {
    int arr[MAX];
    int front, rear;
};

void init(struct Queue *q) { q->front = -1; q->rear = -1; }
int isEmpty(struct Queue *q) { return q->front == -1; }
int isFull(struct Queue *q) { return q->rear == MAX - 1; }

void enqueue(struct Queue *q, int val) {
    if (isFull(q)) { printf("Queue Overflow!\n"); return; }
    if (q->front == -1) q->front = 0;
    q->arr[++(q->rear)] = val;
    printf("Enqueued: %d\n", val);
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) { printf("Queue Underflow!\n"); return -1; }
    int val = q->arr[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return val;
}

void display(struct Queue *q) {
    if (isEmpty(q)) { printf("Queue is empty.\n"); return; }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) printf("%d ", q->arr[i]);
    printf("\n");
}

int main() {
    struct Queue q;
    init(&q);
    int choice, val;
    do {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &val); enqueue(&q, val); break;
            case 2: val = dequeue(&q); if (val != -1) printf("Dequeued: %d\n", val); break;
            case 3: display(&q); break;
            case 4: printf("Exit.\n"); break;
        }
    } while (choice != 4);
    return 0;
}
