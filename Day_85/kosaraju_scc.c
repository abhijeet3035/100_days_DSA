// Day 85: Strongly Connected Components (Kosaraju's Algorithm)
#include <stdio.h>
#define MAX 20

int adj[MAX][MAX] = {0}, radj[MAX][MAX] = {0};
int visited[MAX] = {0}, order[MAX], orderIdx = 0;
int n;

void dfs1(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) if (adj[v][i] && !visited[i]) dfs1(i);
    order[orderIdx++] = v;
}

void dfs2(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) if (radj[v][i] && !visited[i]) dfs2(i);
}

int main() {
    int edges, u, v;
    printf("Enter vertices: "); scanf("%d", &n);
    printf("Enter directed edges: "); scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; radj[v][u] = 1;
    }
    for (int i = 0; i < n; i++) if (!visited[i]) dfs1(i);
    for (int i = 0; i < n; i++) visited[i] = 0;
    printf("Strongly Connected Components:\n");
    int count = 0;
    for (int i = orderIdx - 1; i >= 0; i--) {
        if (!visited[order[i]]) {
            printf("SCC %d: ", ++count);
            dfs2(order[i]);
            printf("\n");
        }
    }
    return 0;
}
