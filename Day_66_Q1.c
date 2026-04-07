/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/

#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adj[node]) {
        // If not visited, recurse
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, recStack))
                return true;
        }
        // If neighbor is in recursion stack → cycle
        else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[node] = false; // backtrack
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<bool> visited(V, false), recStack(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack)) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";
    return 0;
}