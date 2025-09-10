#include <bits/stdc++.h>
using namespace std;

int shortestPath(int V, vector<vector<int> >& edges, int start, int end) {
    vector<vector<int> > adj(V);
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    if (start == end) return 0;

    vector<bool> visited(V, false);
    vector<int> distance(V, -1);
    queue<int> q;

    visited[start] = true;
    distance[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);

                if (neighbor == end) {
                    return distance[neighbor];
                }
            }
        }
    }

    // Step 4: If end is not reachable
    return -1;
}

int main() {
    int V;

    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int> > edges;
    cout << "Enter edges (u v). Enter -1 -1 to stop:\n";

    while (true) {
        int u, v;
        cin >> u >> v;

        if (u == -1 && v == -1) {
            break;
        }
        if (u >= 0 && u < V && v >= 0 && v < V) {
            vector<int> edge(2);
            edge[0] = u;
            edge[1] = v;
            edges.push_back(edge);
        }
    }

    int start, end;
    cout << "Enter start node: ";
    cin >> start;
    cout << "Enter end node: ";
    cin >> end;

    int result = shortestPath(V, edges, start, end);
    
    cout<<result;
    
    return 0;
}
