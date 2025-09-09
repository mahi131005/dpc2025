#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int> > adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // because it's an undirected graph
    }

    // DFS to detect cycle
    bool dfs(int node, int parent, vector<bool> &visited) {
        visited[node] = true;

        for (int i = 0; i < adj[node].size(); i++) {
		    int neighbor = adj[node][i];
		    if (!visited[neighbor]) {
		        if (dfs(neighbor, node, visited))
		            return true;
		    }
		    else if (neighbor != parent) {
		        return true;
		    }
		}

        return false;
    }

    bool hasCycle() {
        vector<bool> visited(V, false);

        // Graph can be disconnected, so check each component
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, visited))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter edges (u v). Enter -1 -1 to stop:\n";
    while (true) {
        int u, v;
        cin >> u >> v;

        if (u == -1 && v == -1) {
            break; 
        }

        g.addEdge(u, v);
    }

    if (g.hasCycle())
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
