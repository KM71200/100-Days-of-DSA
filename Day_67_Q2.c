/*Course Schedule II*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 2000

int adj[MAX][MAX];
int adjSize[MAX];
int visited[MAX];   
int result[MAX];
int index;
int hasCycle = 0;

void dfs(int node) {
    if (hasCycle) return;

    visited[node] = 1; 

    for (int i = 0; i < adjSize[node]; i++) {
        int nei = adj[node][i];

        if (visited[nei] == 0) {
            dfs(nei);
        }
        else if (visited[nei] == 1) {
            hasCycle = 1; 
            return;
        }
    }

    visited[node] = 2; 
    result[index--] = node;
}

int main() {
    int numCourses, m;

    printf("Enter number of courses: ");
    scanf("%d", &numCourses);

    printf("Enter number of prerequisite pairs: ");
    scanf("%d", &m);

    for (int i = 0; i < numCourses; i++) {
        adjSize[i] = 0;
        visited[i] = 0;
    }

    printf("Enter pairs (a b) meaning b -> a:\n");
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        adj[b][adjSize[b]++] = a;
    }

    index = numCourses - 1;

    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == 0) {
            dfs(i);
        }
    }

    if (hasCycle) {
        printf("Cycle detected! No valid course order.\n");
    } else {
        printf("Course order: ");
        for (int i = 0; i < numCourses; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }

    return 0;
}