/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int adjSize[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int nei = adj[node][i];
        if (!visited[nei]) {
            dfs(nei);
        }
    }

    stack[++top] = node;
}

int main() {
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Initialize
    for (int i = 0; i < V; i++) {
        adjSize[i] = 0;
        visited[i] = 0;
    }

    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    printf("\n");

    return 0;
}