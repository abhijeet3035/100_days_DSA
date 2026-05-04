// Day 78: Minimum Spanning Tree - Prim's Algorithm
#include <stdio.h>
#include <limits.h>
#define MAX 20
#define INF INT_MAX

int graph[MAX][MAX], n;

void prims() {
    int parent[MAX], key[MAX], inMST[MAX];
    for (int i = 0; i < n; i++) { key[i] = INF; inMST[i] = 0; }
    key[0] = 0; parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = -1, min = INF;
        for (int v = 0; v < n; v++)
            if (!inMST[v] && key[v] < min) { min = key[v]; u = v; }
        inMST[u] = 1;
        for (int v = 0; v < n; v++)
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v]; parent[v] = u;
            }
    }
    int totalWeight = 0;
    printf("Edge\tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("Total MST weight: %d\n", totalWeight);
}

int main() {
    int edges, u, v, w;
    printf("Enter vertices: "); scanf("%d", &n);
    printf("Enter edges: "); scanf("%d", &edges);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) graph[i][j] = 0;
    for (int i = 0; i < edges; i++) { scanf("%d %d %d", &u, &v, &w); graph[u][v] = graph[v][u] = w; }
    prims();
    return 0;
}
