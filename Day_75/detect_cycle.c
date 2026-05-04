// Day 75: Detect Cycle in Undirected Graph using DFS
#include <stdio.h>
#define MAX 20

int adj[MAX][MAX] = {0}, visited[MAX] = {0};
int n;

int hasCycle(int v, int parent) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (hasCycle(i, v)) return 1;
            } else if (i != parent) return 1;
        }
    }
    return 0;
}

int main() {
    int edges, u, v;
    printf("Enter number of vertices: "); scanf("%d", &n);
    printf("Enter number of edges: "); scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }
    int cycleFound = 0;
    for (int i = 0; i < n; i++)
        if (!visited[i] && hasCycle(i, -1)) { cycleFound = 1; break; }
    printf("Cycle %s\n", cycleFound ? "detected" : "not detected");
    return 0;
}
