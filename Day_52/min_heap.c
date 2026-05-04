// Day 52: Min Heap - Insert and Extract Min
#include <stdio.h>
#define MAX 100

int heap[MAX], heapSize = 0;

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void insertHeap(int val) {
    heap[heapSize] = val;
    int i = heapSize++;
    while (i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void heapify(int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;
    if (l < heapSize && heap[l] < heap[smallest]) smallest = l;
    if (r < heapSize && heap[r] < heap[smallest]) smallest = r;
    if (smallest != i) { swap(&heap[i], &heap[smallest]); heapify(smallest); }
}

int extractMin() {
    if (heapSize == 0) return -1;
    int min = heap[0];
    heap[0] = heap[--heapSize];
    heapify(0);
    return min;
}

void printHeap() {
    printf("Heap: ");
    for (int i = 0; i < heapSize; i++) printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insertHeap(30); insertHeap(10); insertHeap(20);
    insertHeap(5); insertHeap(15);
    printHeap();
    printf("Extracted min: %d\n", extractMin());
    printHeap();
    return 0;
}
