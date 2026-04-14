/*Redundant Connection*/
#include <stdio.h>
#include <stdlib.h>

// Find with path compression
int find(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

// Union
void unionSet(int parent[], int u, int v) {
    int pu = find(parent, u);
    int pv = find(parent, v);
    if (pu != pv)
        parent[pu] = pv;
}

int main() {
    int n;
    printf("Enter number of edges: ");
    scanf("%d", &n);

    int edges[n][2];

    printf("Enter edges (u v):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    int parent[n + 1];

    // Initialize parent
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    // Process edges
    for (int i = 0; i < n; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (find(parent, u) == find(parent, v)) {
            printf("Redundant Edge: [%d, %d]\n", u, v);
            return 0;
        }

        unionSet(parent, u, v);
    }

    printf("No redundant edge found\n");
    return 0;
}