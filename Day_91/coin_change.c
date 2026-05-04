// Day 91: Coin Change Problem (DP)
#include <stdio.h>
#include <limits.h>

int coinChange(int coins[], int n, int amount) {
    int dp[10000];
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) dp[i] = INT_MAX;
    for (int i = 1; i <= amount; i++)
        for (int j = 0; j < n; j++)
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
                if (dp[i - coins[j]] + 1 < dp[i])
                    dp[i] = dp[i - coins[j]] + 1;
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int coins[100], n, amount;
    printf("Enter number of coin types: "); scanf("%d", &n);
    printf("Enter coin values: "); for (int i = 0; i < n; i++) scanf("%d", &coins[i]);
    printf("Enter amount: "); scanf("%d", &amount);
    int result = coinChange(coins, n, amount);
    if (result == -1) printf("Not possible\n");
    else printf("Minimum coins: %d\n", result);
    return 0;
}
