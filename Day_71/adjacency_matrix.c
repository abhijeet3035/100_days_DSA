// Day 71: Graph Representation using Adjacency Matrix
#include <stdio.h>
#define MAX 20

int adj[MAX][MAX] = {0};
int n;

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; // undirected
}

void display() {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

int main() {
    int edges, u, v;
    printf("Enter number of vertices: "); scanf("%d", &n);
    printf("Enter number of edges: "); scanf("%d", &edges);
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    display();
    return 0;
}
