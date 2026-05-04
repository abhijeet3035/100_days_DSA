// Day 20: Count Subarrays with Sum Zero
#include <stdio.h>

int main() {
    int arr[100], n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                count++;
                printf("Subarray [%d..%d] has sum 0\n", i, j);
            }
        }
    }

    printf("Total subarrays with sum zero: %d\n", count);

    return 0;
}
