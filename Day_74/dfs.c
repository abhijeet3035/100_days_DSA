// Day 74: DFS (Depth First Search) of Graph
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
    int edges, u, v, start;
    printf("Enter number of vertices: "); scanf("%d", &n);
    printf("Enter number of edges: "); scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }
    printf("Enter starting vertex: "); scanf("%d", &start);
    printf("DFS: "); dfs(start); printf("\n");
    return 0;
}
