/*Is Graph Bipartite?*/
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Queue implementation
int queue[MAX], front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

bool isEmpty() {
    return front == rear;
}

bool isBipartite(int n, int graph[MAX][MAX]) {
    int color[MAX];

    // initialize all nodes as uncolored
    for (int i = 0; i < n; i++) {
        color[i] = -1;
    }

    // handle disconnected graph
    for (int start = 0; start < n; start++) {

        if (color[start] != -1) continue;

        // start BFS
        front = rear = 0;
        enqueue(start);
        color[start] = 0;

        while (!isEmpty()) {
            int node = dequeue();

            for (int j = 0; j < n; j++) {
                if (graph[node][j] == 1) {

                    if (color[j] == -1) {
                        color[j] = 1 - color[node];
                        enqueue(j);
                    }
                    else if (color[j] == color[node]) {
                        return false; // conflict
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int graph[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (isBipartite(n, graph)) {
        printf("Graph is Bipartite\n");
    } else {
        printf("Graph is NOT Bipartite\n");
    }

    return 0;
}