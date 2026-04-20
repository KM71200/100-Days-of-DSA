/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

struct Node {
    int dest;
    int weight;
    struct Node* next;
};

struct List {
    struct Node* head;
};

struct HeapNode {
    int v;
    int dist;
};

struct MinHeap {
    int size;
    int capacity;
    int* pos; 
    struct HeapNode** array;
};

struct Node* newNode(int dest, int weight) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->dest = dest;
    node->weight = weight;
    node->next = NULL;
    return node;
}

struct HeapNode* newHeapNode(int v, int dist) {
    struct HeapNode* node = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    node->v = v;
    node->dist = dist;
    return node;
}

void swapHeapNode(struct HeapNode** a, struct HeapNode** b) {
    struct HeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        struct HeapNode* smallestNode = minHeap->array[smallest];
        struct HeapNode* idxNode = minHeap->array[idx];

        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        swapHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

struct HeapNode* extractMin(struct MinHeap* minHeap) {
    if (minHeap->size == 0) return NULL;

    struct HeapNode* root = minHeap->array[0];
    struct HeapNode* lastNode = minHeap->array[minHeap->size - 1];

    minHeap->array[0] = lastNode;
    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

void decreaseKey(struct MinHeap* minHeap, int v, int dist) {
    int i = minHeap->pos[v];
    minHeap->array[i]->dist = dist;

    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
        swapHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void dijkstra(struct List* adj, int n, int src) {
    int dist[n + 1];
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->pos = (int*)malloc((n + 1) * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = n;
    minHeap->array = (struct HeapNode**)malloc(n * sizeof(struct HeapNode*));

    for (int v = 1; v <= n; ++v) {
        dist[v] = INF;
        minHeap->array[v - 1] = newHeapNode(v, dist[v]);
        minHeap->pos[v] = v - 1;
    }

    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);
    minHeap->size = n;

    while (minHeap->size != 0) {
        struct HeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;

        struct Node* pCrawl = adj[u].head;
        while (pCrawl != NULL) {
            int v = pCrawl->dest;
            if (minHeap->pos[v] < minHeap->size && dist[u] != INF && pCrawl->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + pCrawl->weight;
                decreaseKey(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    for (int i = 1; i <= n; ++i)
        printf("%d ", dist[i]);
    printf("\n");
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct List* adj = (struct List*)malloc((n + 1) * sizeof(struct List));
    for (int i = 0; i <= n; i++) adj[i].head = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        struct Node* node = newNode(v, w);
        node->next = adj[u].head;
        adj[u].head = node;
        

    }

    int source;
    scanf("%d", &source);

    dijkstra(adj, n, source);

    return 0;
}