// Day 96: Subset Sum Problem (Backtracking / DP)
#include <stdio.h>

int found = 0;

void subsetSum(int arr[], int n, int idx, int currentSum, int target, int subset[], int subsetSize) {
    if (currentSum == target) {
        found = 1;
        printf("Subset: ");
        for (int i = 0; i < subsetSize; i++) printf("%d ", subset[i]);
        printf("\n");
        return;
    }
    if (idx == n || currentSum > target) return;

    subset[subsetSize] = arr[idx];
    subsetSum(arr, n, idx + 1, currentSum + arr[idx], target, subset, subsetSize + 1);
    subsetSum(arr, n, idx + 1, currentSum, target, subset, subsetSize);
}

int main() {
    int arr[100], n, target;
    int subset[100];
    printf("Enter number of elements: "); scanf("%d", &n);
    printf("Enter elements: "); for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter target sum: "); scanf("%d", &target);
    subsetSum(arr, n, 0, 0, target, subset, 0);
    if (!found) printf("No subset found with sum %d\n", target);
    return 0;
}
