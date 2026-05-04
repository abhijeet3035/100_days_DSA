// Day 93: N-Queens Problem (Backtracking)
#include <stdio.h>
#include <math.h>

int board[20], n, count = 0;

int isSafe(int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    return 1;
}

void solve(int row) {
    if (row == n) {
        count++;
        printf("Solution %d: ", count);
        for (int i = 0; i < n; i++) printf("%d ", board[i] + 1);
        printf("\n");
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
        }
    }
}

int main() {
    printf("Enter N: "); scanf("%d", &n);
    solve(0);
    printf("Total solutions: %d\n", count);
    return 0;
}
