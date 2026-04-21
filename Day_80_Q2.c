/*Find the City With the Smallest Number of Neighbors*/
#include <stdio.h>
#include <limits.h>

#define INF 1000000000

int main() {
    int n, m, distanceThreshold;
    scanf("%d %d %d", &n, &m, &distanceThreshold);

    int dist[n][n];

    // Initialize matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Floyd-Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Find city with smallest reachable neighbors
    int minCount = INT_MAX;
    int city = -1;

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distanceThreshold) {
                count++;
            }
        }

        // Tie-breaking: prefer larger index
        if (count <= minCount) {
            minCount = count;
            city = i;
        }
    }

    printf("%d\n", city);

    return 0;
}