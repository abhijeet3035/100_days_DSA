// Day 61: Binary Search (Iterative and Recursive)
#include <stdio.h>

int binarySearchIterative(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == key) return mid;
    if (arr[mid] < key) return binarySearchRecursive(arr, mid + 1, high, key);
    return binarySearchRecursive(arr, low, mid - 1, key);
}

int main() {
    int arr[100], n, key;
    printf("Enter number of sorted elements: "); scanf("%d", &n);
    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter element to search: "); scanf("%d", &key);
    int idx = binarySearchIterative(arr, n, key);
    printf("Iterative: %s", idx != -1 ? "Found at index " : "Not found\n");
    if (idx != -1) printf("%d\n", idx);
    idx = binarySearchRecursive(arr, 0, n-1, key);
    printf("Recursive: %s", idx != -1 ? "Found at index " : "Not found\n");
    if (idx != -1) printf("%d\n", idx);
    return 0;
}
