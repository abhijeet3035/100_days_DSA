// Day 64: Interpolation Search
#include <stdio.h>

int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) { return (arr[low] == key) ? low : -1; }
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]));
        if (arr[pos] == key) return pos;
        if (arr[pos] < key) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int main() {
    int arr[100], n, key;
    printf("Enter number of sorted elements: "); scanf("%d", &n);
    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter element to search: "); scanf("%d", &key);
    int idx = interpolationSearch(arr, n, key);
    if (idx != -1) printf("Found at index %d\n", idx);
    else printf("Not found\n");
    return 0;
}
