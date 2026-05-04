// Day 99: Graph Coloring Problem (Backtracking)
#include <stdio.h>
#define MAX 20

int adj[MAX][MAX] = {0}, color[MAX] = {0};
int n, m; // vertices, colors

int isSafe(int v, int c) {
    for (int i = 0; i < n; i++)
        if (adj[v][i] && color[i] == c) return 0;
    return 1;
}

int solve(int v) {
    if (v == n) return 1;
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;
            if (solve(v + 1)) return 1;
            color[v] = 0;
        }
    }
    return 0;
}

int main() {
    int edges, u, v;
    printf("Enter vertices: "); scanf("%d", &n);
    printf("Enter edges: "); scanf("%d", &edges);
    for (int i = 0; i < edges; i++) { scanf("%d %d", &u, &v); adj[u][v] = adj[v][u] = 1; }
    printf("Enter number of colors: "); scanf("%d", &m);
    if (solve(0)) {
        printf("Coloring: ");
        for (int i = 0; i < n; i++) printf("V%d=C%d ", i, color[i]);
        printf("\n");
    } else printf("No solution with %d colors.\n", m);
    return 0;
}
