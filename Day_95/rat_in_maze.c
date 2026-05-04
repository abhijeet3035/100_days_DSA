// Day 95: Rat in a Maze (Backtracking)
#include <stdio.h>
#define N 10

int maze[N][N], sol[N][N];
int n;

int isSafe(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1;
}

int solve(int x, int y) {
    if (x == n-1 && y == n-1) { sol[x][y] = 1; return 1; }
    if (isSafe(x, y)) {
        sol[x][y] = 1;
        if (solve(x + 1, y)) return 1;
        if (solve(x, y + 1)) return 1;
        sol[x][y] = 0;
    }
    return 0;
}

int main() {
    printf("Enter maze size: "); scanf("%d", &n);
    printf("Enter maze (1=open, 0=blocked):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) { scanf("%d", &maze[i][j]); sol[i][j] = 0; }
    if (solve(0, 0)) {
        printf("Path:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) printf("%d ", sol[i][j]);
            printf("\n");
        }
    } else printf("No path exists.\n");
    return 0;
}
