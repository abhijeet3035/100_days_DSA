// Day 69: Find Duplicates using Hashing
#include <stdio.h>
#define MAX_VAL 1000

int main() {
    int arr[100], n;
    int hash[MAX_VAL] = {0};

    printf("Enter number of elements: "); scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Duplicates: ");
    int found = 0;
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
        if (hash[arr[i]] == 2) { printf("%d ", arr[i]); found = 1; }
    }
    if (!found) printf("None");
    printf("\n");
    return 0;
}
