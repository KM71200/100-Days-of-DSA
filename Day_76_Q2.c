/*Clone Graph*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

struct Node* visited[101];

struct Node* dfs(struct Node* node) {
    if (!node) return NULL;
    if (visited[node->val]) return visited[node->val];

    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = node->numNeighbors > 0
        ? (struct Node**)malloc(node->numNeighbors * sizeof(struct Node*))
        : NULL;

    visited[node->val] = clone;

    for (int i = 0; i < node->numNeighbors; i++)
        clone->neighbors[i] = dfs(node->neighbors[i]);

    return clone;
}

struct Node* cloneGraph(struct Node* s) {
    if (!s) return NULL;
    memset(visited, 0, sizeof(visited));
    return dfs(s);
}

struct Node* buildGraph(int adjList[][4], int sizes[], int n) {
    struct Node** nodes = (struct Node**)malloc((n + 1) * sizeof(struct Node*));

    for (int i = 1; i <= n; i++) {
        nodes[i] = (struct Node*)malloc(sizeof(struct Node));
        nodes[i]->val = i;
        nodes[i]->numNeighbors = sizes[i - 1];
        nodes[i]->neighbors = sizes[i - 1] > 0
            ? (struct Node**)malloc(sizes[i - 1] * sizeof(struct Node*))
            : NULL;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < sizes[i - 1]; j++)
            nodes[i]->neighbors[j] = nodes[adjList[i - 1][j]];

    struct Node* start = nodes[1];
    free(nodes);
    return start;
}

void printGraph(struct Node* start, int n) {
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int visited_print[101] = {0};
    int front = 0, back = 0;

    queue[back++] = start;
    visited_print[start->val] = 1;

    printf("Adjacency List:\n");
    while (front < back) {
        struct Node* cur = queue[front++];
        printf("  Node %d -> [", cur->val);
        for (int i = 0; i < cur->numNeighbors; i++) {
            printf("%d", cur->neighbors[i]->val);
            if (i < cur->numNeighbors - 1) printf(", ");
            if (!visited_print[cur->neighbors[i]->val]) {
                visited_print[cur->neighbors[i]->val] = 1;
                queue[back++] = cur->neighbors[i];
            }
        }
        printf("]\n");
    }
    free(queue);
}

void freeGraph(struct Node* start, int n) {
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int vis[101] = {0};
    int front = 0, back = 0;

    queue[back++] = start;
    vis[start->val] = 1;

    while (front < back) {
        struct Node* cur = queue[front++];
        for (int i = 0; i < cur->numNeighbors; i++)
            if (!vis[cur->neighbors[i]->val]) {
                vis[cur->neighbors[i]->val] = 1;
                queue[back++] = cur->neighbors[i];
            }
        free(cur->neighbors);
        free(cur);
    }
    free(queue);
}

int main() {
    int adjList[4][4] = {
        {2, 4},  
        {1, 3},   
        {2, 4},   
        {1, 3}    
    };
    int sizes[] = {2, 2, 2, 2};
    int n = 4;

    printf("=== Example 1 ===\n");
    struct Node* original = buildGraph(adjList, sizes, n);
    printf("Original Graph:\n");
    printGraph(original, n);

    struct Node* cloned = cloneGraph(original);
    printf("\nCloned Graph:\n");
    printGraph(cloned, n);

    printf("\nDeep copy check (pointers must differ):\n");
    printf("  original node1 addr: %p\n", (void*)original);
    printf("  cloned   node1 addr: %p\n", (void*)cloned);
    printf("  Are they different?  %s\n", original != cloned ? "YES ✓" : "NO ✗");

    printf("\n=== Example 2 (single node) ===\n");
    struct Node* single = (struct Node*)malloc(sizeof(struct Node));
    single->val = 1;
    single->numNeighbors = 0;
    single->neighbors = NULL;

    struct Node* clonedSingle = cloneGraph(single);
    printf("Original node val: %d, addr: %p\n", single->val,       (void*)single);
    printf("Cloned   node val: %d, addr: %p\n", clonedSingle->val, (void*)clonedSingle);
    printf("Are they different? %s\n", single != clonedSingle ? "YES ✓" : "NO ✗");

    freeGraph(original, n);
    freeGraph(cloned, n);
    free(single);
    free(clonedSingle);

    return 0;
}