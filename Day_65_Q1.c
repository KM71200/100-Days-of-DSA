/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.
Output:
- YES or NO*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool dfs(int node, int parent, bool visited[], int adj[MAX][MAX], int n) {
    visited[node] = true;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {  // if edge exists
            if (!visited[i]) {
                if (dfs(i, node, visited, adj, n))
                    return true;
            }
            else if (i != parent) {
                return true;  // cycle found
            }
        }
    }
    return false;
}

const char* hasCycle(int n, int adj[MAX][MAX]) {
    bool visited[MAX] = {false};

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj, n))
                return "YES";
        }
    }
    return "NO";
}

int main() {
    int n = 5;

    int adj[MAX][MAX] = {0};

    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[2][3] = adj[3][2] = 1;
    adj[3][4] = adj[4][3] = 1;
    adj[4][1] = adj[1][4] = 1; 

    printf("%s\n", hasCycle(n, adj));  

    return 0;
}