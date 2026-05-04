// Day 73: BFS (Breadth First Search) of Graph
#include <stdio.h>
#define MAX 20

int adj[MAX][MAX] = {0}, visited[MAX] = {0};
int queue[MAX], front = -1, rear = -1;
int n;

void enqueue(int v) { queue[++rear] = v; if (front == -1) front = 0; }
int dequeue() { return queue[front++]; }
int isEmpty() { return front == -1 || front > rear; }

void bfs(int start) {
    visited[start] = 1;
    enqueue(start);
    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    int edges, u, v, start;
    printf("Enter number of vertices: "); scanf("%d", &n);
    printf("Enter number of edges: "); scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }
    printf("Enter starting vertex: "); scanf("%d", &start);
    printf("BFS: "); bfs(start); printf("\n");
    return 0;
}
