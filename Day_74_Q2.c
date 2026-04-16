/*Number of Connected Components in an Undirected Graph*/
#include <stdio.h>
#include <stdbool.h>

// DFS function
void dfs(int n, int isConnected[n][n], int city, bool visited[]) {
    visited[city] = true;

    for (int j = 0; j < n; j++) {
        if (isConnected[city][j] == 1 && !visited[j]) {
            dfs(n, isConnected, j, visited);
        }
    }
}

// Function to count provinces
int findCircleNum(int n, int isConnected[n][n]) {
    bool visited[n];

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(n, isConnected, i, visited);
            provinces++;
        }
    }

    return provinces;
}

int main() {
    int n;
    printf("Enter number of cities: ");
    scanf("%d", &n);

    int isConnected[n][n];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }

    int result = findCircleNum(n, isConnected);

    printf("Number of Provinces: %d\n", result);

    return 0;
}