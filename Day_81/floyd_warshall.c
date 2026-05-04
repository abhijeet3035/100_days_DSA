// Day 81: Floyd-Warshall All-Pairs Shortest Path
#include <stdio.h>
#define MAX 20
#define INF 99999

int dist[MAX][MAX], n;

void floydWarshall() {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}

int main() {
    int edges, u, v, w;
    printf("Enter vertices: "); scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) dist[i][j] = (i == j) ? 0 : INF;
    printf("Enter edges: "); scanf("%d", &edges);
    for (int i = 0; i < edges; i++) { scanf("%d %d %d", &u, &v, &w); dist[u][v] = w; }
    floydWarshall();
    printf("Shortest distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf(dist[i][j] >= INF ? "INF " : "%3d ", dist[i][j]);
        printf("\n");
    }
    return 0;
}
