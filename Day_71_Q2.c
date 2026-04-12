
/*Min Cost to Connect All Points*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int absVal(int x) {
    return x < 0 ? -x : x;
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    
    int *minDist = (int*)malloc(n * sizeof(int));
    int *visited = (int*)calloc(n, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        minDist[i] = INT_MAX;
    }
    
    minDist[0] = 0;
    int totalCost = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        totalCost += minDist[u];

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int dist = absVal(points[u][0] - points[v][0]) +
                           absVal(points[u][1] - points[v][1]);

                if (dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }

    free(minDist);
    free(visited);

    return totalCost;
}

int main() {
    int n;
    scanf("%d", &n);

    int** points = (int**)malloc(n * sizeof(int*));
    int* pointsColSize = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        points[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &points[i][0], &points[i][1]);
        pointsColSize[i] = 2;
    }

    int result = minCostConnectPoints(points, n, pointsColSize);
    printf("%d\n", result);

    // free memory
    for (int i = 0; i < n; i++) {
        free(points[i]);
    }
    free(points);
    free(pointsColSize);

    return 0;
}