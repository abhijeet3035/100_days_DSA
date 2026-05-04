// Day 80: Bellman-Ford Shortest Path Algorithm
#include <stdio.h>
#include <limits.h>
#define MAX 100
#define INF INT_MAX

struct Edge { int u, v, w; };
struct Edge edges[MAX];
int dist[MAX];
int n, e;

void bellmanFord(int src) {
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < e; j++)
            if (dist[edges[j].u] != INF && dist[edges[j].u] + edges[j].w < dist[edges[j].v])
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
    // Check negative cycle
    for (int j = 0; j < e; j++)
        if (dist[edges[j].u] != INF && dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
            printf("Negative weight cycle detected!\n"); return;
        }
    printf("Vertex\tDist from %d\n", src);
    for (int i = 0; i < n; i++) printf("%d\t%d\n", i, dist[i]);
}

int main() {
    int src;
    printf("Enter vertices and edges: "); scanf("%d %d", &n, &e);
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++) scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    printf("Source: "); scanf("%d", &src);
    bellmanFord(src);
    return 0;
}
