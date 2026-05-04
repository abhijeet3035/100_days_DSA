// Day 90: Edit Distance (DP)
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a < b) return a < c ? a : c;
    return b < c ? b : c;
}

int editDistance(char *s1, char *s2) {
    int m = strlen(s1), n = strlen(s2);
    int dp[100][100];
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    return dp[m][n];
}

int main() {
    char s1[100], s2[100];
    printf("Enter first string: "); scanf("%s", s1);
    printf("Enter second string: "); scanf("%s", s2);
    printf("Edit distance: %d\n", editDistance(s1, s2));
    return 0;
}
