/*Strongly Connected Components*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int to;
    int next;
} Edge;

Edge *edges_pool;
Edge *rev_edges_pool;
int *head, *rev_head;
int *stack;
bool *visited;
int edge_cnt, rev_edge_cnt, stack_ptr;

void add_edge(int u, int v) {
    edges_pool[edge_cnt].to = v;
    edges_pool[edge_cnt].next = head[u];
    head[u] = edge_cnt++;
}

void add_rev_edge(int u, int v) {
    rev_edges_pool[rev_edge_cnt].to = v;
    rev_edges_pool[rev_edge_cnt].next = rev_head[u];
    rev_head[u] = rev_edge_cnt++;
}

void dfs1(int u) {
    visited[u] = true;
    for (int i = head[u]; i != -1; i = edges_pool[i].next) {
        int v = edges_pool[i].to;
        if (!visited[v]) {
            dfs1(v);
        }
    }
    stack[stack_ptr++] = u;
}

void dfs2(int u) {
    visited[u] = true;
    for (int i = rev_head[u]; i != -1; i = rev_edges_pool[i].next) {
        int v = rev_edges_pool[i].to;
        if (!visited[v]) {
            dfs2(v);
        }
    }
}

int main() {
    int V, E;
    if (scanf("%d %d", &V, &E) != 2) return 0;

    edges_pool = (Edge *)malloc(E * sizeof(Edge));
    rev_edges_pool = (Edge *)malloc(E * sizeof(Edge));
    head = (int *)malloc(V * sizeof(int));
    rev_head = (int *)malloc(V * sizeof(int));
    stack = (int *)malloc(V * sizeof(int));
    visited = (bool *)malloc(V * sizeof(bool));

    for (int i = 0; i < V; i++) {
        head[i] = rev_head[i] = -1;
        visited[i] = false;
    }

    edge_cnt = rev_edge_cnt = stack_ptr = 0;

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_rev_edge(v, u);
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    int scc_count = 0;
    while (stack_ptr > 0) {
        int u = stack[--stack_ptr];
        if (!visited[u]) {
            scc_count++;
            dfs2(u);
        }
    }

    printf("%d\n", scc_count);

    free(edges_pool); free(rev_edges_pool);
    free(head); free(rev_head);
    free(stack); free(visited);

    return 0;
}