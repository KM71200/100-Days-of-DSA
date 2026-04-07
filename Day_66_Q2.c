/*Course Schedule*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int node, int** adj, int* adjSize, bool* visited, bool* recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, adjSize, visited, recStack))
                return true;
        }
        else if (recStack[neighbor]) {
            return true; 
        }
    }

    recStack[node] = false;
    return false;
}

bool canFinish(int numCourses, int prerequisites[][2], int prerequisitesSize) {

    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < prerequisitesSize; i++) {
        int from = prerequisites[i][1];
        adjSize[from]++;
    }

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0;
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int from = prerequisites[i][1];
        int to = prerequisites[i][0];
        adj[from][adjSize[from]++] = to;
    }

    bool* visited = (bool*)calloc(numCourses, sizeof(bool));
    bool* recStack = (bool*)calloc(numCourses, sizeof(bool));

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, adjSize, visited, recStack))
                return false;
        }
    }

    return true;
}

int main() {
    int numCourses = 2;

    int prerequisites1[][2] = {{1,0}};
    int size1 = 1;

    if (canFinish(numCourses, prerequisites1, size1))
        printf("true\n");
    else
        printf("false\n");

    int prerequisites2[][2] = {{1,0},{0,1}};
    int size2 = 2;

    if (canFinish(numCourses, prerequisites2, size2))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}