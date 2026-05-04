// Day 77: Topological Sort using DFS
#include <stdio.h>
#define MAX 20

int adj[MAX][MAX] = {0}, visited[MAX] = {0};
int stack[MAX], top = -1;
int n;

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++)
        if (adj[v][i] && !visited[i]) dfs(i);
    stack[++top] = v;
}

void topologicalSort() {
    for (int i = 0; i < n; i++)
        if (!visited[i]) dfs(i);
    printf("Topological Order: ");
    while (top >= 0) printf("%d ", stack[top--]);
    printf("\n");
}

int main() {
    int edges, u, v;
    printf("Enter vertices: "); scanf("%d", &n);
    printf("Enter directed edges: "); scanf("%d", &edges);
    for (int i = 0; i < edges; i++) { scanf("%d %d", &u, &v); adj[u][v] = 1; }
    topologicalSort();
    return 0;
}
