// Day 70: Two Sum Problem using Hashing
#include <stdio.h>
#define MAX_VAL 10000

int main() {
    int arr[100], n, target;
    int hash[MAX_VAL * 2] = {0}; // offset for negatives
    int offset = MAX_VAL;

    printf("Enter number of elements: "); scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter target sum: "); scanf("%d", &target);

    printf("Pairs with sum %d:\n", target);
    int found = 0;
    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        if (complement + offset >= 0 && complement + offset < MAX_VAL * 2 && hash[complement + offset]) {
            printf("(%d, %d)\n", complement, arr[i]);
            found = 1;
        }
        hash[arr[i] + offset] = 1;
    }
    if (!found) printf("No pairs found.\n");
    return 0;
}
