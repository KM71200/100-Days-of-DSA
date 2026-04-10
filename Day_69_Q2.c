/*Network delay time*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 101

struct Node {
    int v, w;
    struct Node* next;
};

struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v, int w) {
    struct Node* node = createNode(v, w);
    node->next = adj[u];
    adj[u] = node;
}

struct HeapNode {
    int v, dist;
};

struct MinHeap {
    int size;
    struct HeapNode arr[10000];
};

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(struct MinHeap* h, int i) {
    while (i > 0 && h->arr[(i - 1)/2].dist > h->arr[i].dist) {
        swap(&h->arr[i], &h->arr[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

void heapifyDown(struct MinHeap* h, int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < h->size && h->arr[l].dist < h->arr[smallest].dist)
        smallest = l;
    if (r < h->size && h->arr[r].dist < h->arr[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        heapifyDown(h, smallest);
    }
}

void push(struct MinHeap* h, int v, int dist) {
    int i = h->size++;
    h->arr[i].v = v;
    h->arr[i].dist = dist;
    heapifyUp(h, i);
}

struct HeapNode pop(struct MinHeap* h) {
    struct HeapNode root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    heapifyDown(h, 0);
    return root;
}

int networkDelayTime(int times[][3], int timesSize, int n, int k) {

    struct Node* adj[MAX] = {NULL};

    for (int i = 0; i < timesSize; i++) {
        addEdge(adj, times[i][0], times[i][1], times[i][2]);
    }

    int dist[MAX];
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    struct MinHeap heap;
    heap.size = 0;

    dist[k] = 0;
    push(&heap, k, 0);

    while (heap.size > 0) {
        struct HeapNode node = pop(&heap);
        int u = node.v;

        if (node.dist > dist[u]) continue;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    int maxTime = 0;

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            return -1;
        if (dist[i] > maxTime)
            maxTime = dist[i];
    }

    return maxTime;
}

int main() {
    // Example 1
    int times[][3] = {
        {2,1,1},
        {2,3,1},
        {3,4,1}
    };

    int n = 4;
    int k = 2;
    int timesSize = 3;

    int result = networkDelayTime(times, timesSize, n, k);

    printf("Network Delay Time: %d\n", result);

    return 0;
}