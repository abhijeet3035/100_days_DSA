// Day 55: Kth Largest Element using Max Heap
#include <stdio.h>

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void heapify(int arr[], int n, int i) {
    int largest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) { swap(&arr[i], &arr[largest]); heapify(arr, n, largest); }
}

int kthLargest(int arr[], int n, int k) {
    // Build max heap
    for (int i = n/2 - 1; i >= 0; i--) heapify(arr, n, i);
    // Extract k times
    int size = n;
    for (int i = 0; i < k - 1; i++) {
        swap(&arr[0], &arr[size - 1]);
        size--;
        heapify(arr, size, 0);
    }
    return arr[0];
}

int main() {
    int arr[100], n, k;
    printf("Enter number of elements: "); scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter k: "); scanf("%d", &k);
    printf("%dth largest element: %d\n", k, kthLargest(arr, n, k));
    return 0;
}
