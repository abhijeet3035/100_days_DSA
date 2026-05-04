// Day 79: Kruskal's MST Algorithm
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Edge { int u, v, w; };
struct Edge edges[MAX];
int parent[MAX], rank_arr[MAX];
int n, e;

int find(int x) { if (parent[x] != x) parent[x] = find(parent[x]); return parent[x]; }

void unionSets(int x, int y) {
    int px = find(x), py = find(y);
    if (rank_arr[px] < rank_arr[py]) parent[px] = py;
    else if (rank_arr[px] > rank_arr[py]) parent[py] = px;
    else { parent[py] = px; rank_arr[px]++; }
}

int cmp(const void *a, const void *b) {
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

void kruskal() {
    qsort(edges, e, sizeof(struct Edge), cmp);
    for (int i = 0; i < n; i++) { parent[i] = i; rank_arr[i] = 0; }
    int totalWeight = 0, count = 0;
    printf("MST Edges:\n");
    for (int i = 0; i < e && count < n - 1; i++) {
        int pu = find(edges[i].u), pv = find(edges[i].v);
        if (pu != pv) {
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].w);
            totalWeight += edges[i].w;
            unionSets(pu, pv);
            count++;
        }
    }
    printf("Total MST weight: %d\n", totalWeight);
}

int main() {
    printf("Enter vertices and edges: "); scanf("%d %d", &n, &e);
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++) scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    kruskal();
    return 0;
}
