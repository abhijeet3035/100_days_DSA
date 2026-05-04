// Day 92: Rod Cutting Problem (DP)
#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int rodCutting(int price[], int n) {
    int dp[100];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int maxVal = -1;
        for (int j = 0; j < i; j++)
            maxVal = max(maxVal, price[j] + dp[i - j - 1]);
        dp[i] = maxVal;
    }
    return dp[n];
}

int main() {
    int price[100], n;
    printf("Enter length of rod: "); scanf("%d", &n);
    printf("Enter prices for lengths 1 to %d: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &price[i]);
    printf("Maximum obtainable value: %d\n", rodCutting(price, n));
    return 0;
}
