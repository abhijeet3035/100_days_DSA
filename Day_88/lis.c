// Day 88: Longest Increasing Subsequence (DP)
#include <stdio.h>

int lis(int arr[], int n) {
    int dp[100], maxLen = 1;
    for (int i = 0; i < n; i++) dp[i] = 1;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
    for (int i = 0; i < n; i++)
        if (dp[i] > maxLen) maxLen = dp[i];
    return maxLen;
}

int main() {
    int arr[100], n;
    printf("Enter number of elements: "); scanf("%d", &n);
    printf("Enter elements: "); for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Length of LIS: %d\n", lis(arr, n));
    return 0;
}
