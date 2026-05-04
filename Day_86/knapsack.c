// Day 86: 0/1 Knapsack Problem (Dynamic Programming)
#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int knapsack(int W, int wt[], int val[], int n) {
    int dp[100][100];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
            else dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;
    int val[100], wt[100];
    printf("Enter number of items: "); scanf("%d", &n);
    printf("Enter values: "); for (int i = 0; i < n; i++) scanf("%d", &val[i]);
    printf("Enter weights: "); for (int i = 0; i < n; i++) scanf("%d", &wt[i]);
    printf("Enter capacity: "); scanf("%d", &W);
    printf("Maximum value: %d\n", knapsack(W, wt, val, n));
    return 0;
}
