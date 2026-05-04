// Day 19: Pair Sum Closest to Zero
#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[100], n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n < 2) {
        printf("Need at least 2 elements.\n");
        return 1;
    }

    int minSum = abs(arr[0] + arr[1]);
    int p1 = 0, p2 = 1;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = abs(arr[i] + arr[j]);
            if (sum < minSum) {
                minSum = sum;
                p1 = i;
                p2 = j;
            }
        }
    }

    printf("Pair with sum closest to zero: (%d, %d)\n", arr[p1], arr[p2]);
    printf("Sum: %d\n", arr[p1] + arr[p2]);

    return 0;
}
