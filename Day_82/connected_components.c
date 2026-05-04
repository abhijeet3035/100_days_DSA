// Day 82: Connected Components in Undirected Graph
#include <stdio.h>
#define MAX 20

int adj[MAX][MAX] = {0}, visited[MAX] = {0};
int n;

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++)
        if (adj[v][i] && !visited[i]) dfs(i);
}

int main() {
    int edges, u, v;
    printf("Enter vertices: "); scanf("%d", &n);
    printf("Enter edges: "); scanf("%d", &edges);
    for (int i = 0; i < edges; i++) { scanf("%d %d", &u, &v); adj[u][v] = adj[v][u] = 1; }
    int count = 0;
    printf("Connected Components:\n");
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("Component %d: ", ++count);
            dfs(i);
            printf("\n");
        }
    }
    printf("Total components: %d\n", count);
    return 0;
}
