// Day 84: Detect Cycle in Directed Graph using DFS
#include <stdio.h>
#define MAX 20

int adj[MAX][MAX] = {0}, visited[MAX] = {0}, recStack[MAX] = {0};
int n;

int hasCycleDFS(int v) {
    visited[v] = 1;
    recStack[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i] && hasCycleDFS(i)) return 1;
            else if (recStack[i]) return 1;
        }
    }
    recStack[v] = 0;
    return 0;
}

int main() {
    int edges, u, v;
    printf("Enter vertices: "); scanf("%d", &n);
    printf("Enter directed edges: "); scanf("%d", &edges);
    for (int i = 0; i < edges; i++) { scanf("%d %d", &u, &v); adj[u][v] = 1; }
    int cycleFound = 0;
    for (int i = 0; i < n; i++)
        if (!visited[i] && hasCycleDFS(i)) { cycleFound = 1; break; }
    printf("Cycle %s in directed graph\n", cycleFound ? "detected" : "not detected");
    return 0;
}
