/*Articulation points*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// adjacency list node
struct Node {
    int data;
    struct Node* next;
};

// create new node
struct Node* newNode(int v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = v;
    temp->next = NULL;
    return temp;
}

// add edge (undirected)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* temp = newNode(v);
    temp->next = adj[u];
    adj[u] = temp;

    temp = newNode(u);
    temp->next = adj[v];
    adj[v] = temp;
}

void dfs(int u, int parent, struct Node* adj[],
         int visited[], int disc[], int low[],
         int ap[], int* timer) {

    visited[u] = 1;
    disc[u] = low[u] = (*timer)++;
    int children = 0;

    struct Node* temp = adj[u];

    while (temp) {
        int v = temp->data;

        if (!visited[v]) {
            children++;
            dfs(v, u, adj, visited, disc, low, ap, timer);

            if (low[v] < low[u])
                low[u] = low[v];

            if (parent != -1 && low[v] >= disc[u])
                ap[u] = 1;
        }
        else if (v != parent) {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }

        temp = temp->next;
    }

    if (parent == -1 && children > 1)
        ap[u] = 1;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Node* adj[MAX] = {NULL};

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int visited[MAX] = {0}, disc[MAX], low[MAX], ap[MAX] = {0};
    int timer = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, -1, adj, visited, disc, low, ap, &timer);
        }
    }

    int found = 0;
    for (int i = 0; i < V; i++) {
        if (ap[i]) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found)
        printf("-1");

    return 0;
}