// Day 62: Counting Sort
#include <stdio.h>
#include <string.h>

void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];

    int count[1000] = {0};
    for (int i = 0; i < n; i++) count[arr[i]]++;
    for (int i = 1; i <= max; i++) count[i] += count[i-1];

    int output[100];
    for (int i = n-1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++) arr[i] = output[i];
}

int main() {
    int arr[100], n;
    printf("Enter number of elements: "); scanf("%d", &n);
    printf("Enter elements (non-negative): ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    countingSort(arr, n);
    printf("Sorted: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
