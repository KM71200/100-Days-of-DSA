#include <stdio.h>

#define MAX 100

void dfs(int adj[MAX][MAX], int visited[], int n, int city) {
    visited[city] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[city][i] == 1 && !visited[i]) {
            dfs(adj, visited, n, i);
        }
    }
}

int main() {
    int n;
    int adj[MAX][MAX];
    int visited[MAX] = {0};
    int provinces = 0;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(adj, visited, n, i);
            provinces++;
        }
    }

    printf("Number of provinces: %d\n", provinces);

    return 0;
}
