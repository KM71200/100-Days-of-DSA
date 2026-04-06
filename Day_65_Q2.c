/*Graph Cycle Detection*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int node, int parent, bool *visited, int **adj, int *adjSize) {
    visited[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, visited, adj, adjSize))
                return true;
        }
        else if (neighbor != parent) {
            return true; // cycle found
        }
    }
    return false;
}

bool isCycle(int edges[][2], int E, int V) {

    int *adjSize = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < E; i++) {
        adjSize[edges[i][0]]++;
        adjSize[edges[i][1]]++;
    }

    int **adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0; // reset
    }

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    bool *visited = (bool*)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj, adjSize)) {
                // free memory before returning
                for (int j = 0; j < V; j++) free(adj[j]);
                free(adj);
                free(adjSize);
                free(visited);
                return true;
            }
        }
    }

    for (int i = 0; i < V; i++) free(adj[i]);
    free(adj);
    free(adjSize);
    free(visited);

    return false;
}

int main() {
    int V = 4, E = 4;

    int edges[4][2] = {
        {0,1}, {0,2}, {1,2}, {2,3}
    };

    if (isCycle(edges, E, V))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}