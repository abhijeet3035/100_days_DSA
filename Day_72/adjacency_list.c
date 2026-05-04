// Day 72: Graph Representation using Adjacency List
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct Node {
    int data;
    struct Node *next;
};

struct Node* adjList[MAX] = {NULL};
int n;

void addEdge(int u, int v) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v; newNode->next = adjList[u]; adjList[u] = newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = u; newNode->next = adjList[v]; adjList[v] = newNode;
}

void display() {
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node *temp = adjList[i];
        while (temp) { printf("%d -> ", temp->data); temp = temp->next; }
        printf("NULL\n");
    }
}

int main() {
    int edges, u, v;
    printf("Enter number of vertices: "); scanf("%d", &n);
    printf("Enter number of edges: "); scanf("%d", &edges);
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) { scanf("%d %d", &u, &v); addEdge(u, v); }
    printf("Adjacency List:\n");
    display();
    return 0;
}
