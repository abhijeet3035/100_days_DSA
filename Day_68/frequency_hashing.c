// Day 68: Frequency Count using Hashing
#include <stdio.h>
#define MAX_VAL 1000

int main() {
    int arr[100], n;
    int freq[MAX_VAL] = {0};

    printf("Enter number of elements: "); scanf("%d", &n);
    printf("Enter elements (0-%d): ", MAX_VAL-1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[arr[i]]++;
    }

    printf("\nElement | Frequency\n");
    printf("--------|----------\n");
    for (int i = 0; i < MAX_VAL; i++)
        if (freq[i] > 0) printf("%7d | %d\n", i, freq[i]);

    return 0;
}
