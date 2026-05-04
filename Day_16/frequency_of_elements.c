// Day 16: Find Frequency of Elements in Array
#include <stdio.h>

int main() {
    int arr[100], freq[100], n;
    int visited = -1;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                freq[j] = 0; // Mark as counted
            }
        }
        if (freq[i] != 0) {
            freq[i] = count;
        }
    }

    printf("Element | Frequency\n");
    printf("--------|----------\n");
    for (int i = 0; i < n; i++) {
        if (freq[i] != 0) {
            printf("%7d | %d\n", arr[i], freq[i]);
        }
    }

    return 0;
}
