// Day 76: Dijkstra's Shortest Path Algorithm
#include <stdio.h>
#include <limits.h>
#define MAX 20
#define INF INT_MAX

int graph[MAX][MAX], dist[MAX], visited[MAX];
int n;

int minDist() {
    int min = INF, idx = -1;
    for (int i = 0; i < n; i++)
        if (!visited[i] && dist[i] < min) { min = dist[i]; idx = i; }
    return idx;
}

void dijkstra(int src) {
    for (int i = 0; i < n; i++) { dist[i] = INF; visited[i] = 0; }
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++) {
        int u = minDist();
        if (u == -1) break;
        visited[u] = 1;
        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printf("Vertex\tDistance from %d\n", src);
    for (int i = 0; i < n; i++) printf("%d\t%d\n", i, dist[i]);
}

int main() {
    int edges, u, v, w, src;
    printf("Enter vertices: "); scanf("%d", &n);
    printf("Enter edges: "); scanf("%d", &edges);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) graph[i][j] = 0;
    for (int i = 0; i < edges; i++) { scanf("%d %d %d", &u, &v, &w); graph[u][v] = graph[v][u] = w; }
    printf("Source: "); scanf("%d", &src);
    dijkstra(src);
    return 0;
}
