// Day 83: Bipartite Graph Check using BFS
#include <stdio.h>
#define MAX 20

int adj[MAX][MAX] = {0}, color[MAX];
int queue[MAX], front, rear;
int n;

int isBipartite(int src) {
    for (int i = 0; i < n; i++) color[i] = -1;
    front = rear = 0;
    color[src] = 0;
    queue[rear++] = src;
    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                if (color[v] == -1) { color[v] = 1 - color[u]; queue[rear++] = v; }
                else if (color[v] == color[u]) return 0;
            }
        }
    }
    return 1;
}

int main() {
    int edges, u, v;
    printf("Enter vertices: "); scanf("%d", &n);
    printf("Enter edges: "); scanf("%d", &edges);
    for (int i = 0; i < edges; i++) { scanf("%d %d", &u, &v); adj[u][v] = adj[v][u] = 1; }
    printf("Graph is %s\n", isBipartite(0) ? "Bipartite" : "Not Bipartite");
    return 0;
}
