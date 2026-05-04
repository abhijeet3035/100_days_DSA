// Day 94: Sudoku Solver (Backtracking)
#include <stdio.h>
#define N 9

int grid[N][N];

int isSafe(int row, int col, int num) {
    for (int x = 0; x < N; x++) if (grid[row][x] == num) return 0;
    for (int x = 0; x < N; x++) if (grid[x][col] == num) return 0;
    int sr = row - row % 3, sc = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + sr][j + sc] == num) return 0;
    return 1;
}

int solve() {
    int row = -1, col = -1;
    for (int i = 0; i < N && row == -1; i++)
        for (int j = 0; j < N && row == -1; j++)
            if (grid[i][j] == 0) { row = i; col = j; }
    if (row == -1) return 1;
    for (int num = 1; num <= 9; num++) {
        if (isSafe(row, col, num)) {
            grid[row][col] = num;
            if (solve()) return 1;
            grid[row][col] = 0;
        }
    }
    return 0;
}

void print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf("%d ", grid[i][j]);
        printf("\n");
    }
}

int main() {
    printf("Enter 9x9 Sudoku grid (0 for empty):\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) scanf("%d", &grid[i][j]);
    if (solve()) { printf("Solved:\n"); print(); }
    else printf("No solution exists.\n");
    return 0;
}
