#include <iostream>
#include <vector>
using namespace std;

void dfshelper(int node, vector<bool>& visited, vector<vector<int>>& adj, vector<int> &ans) {
    visited[node] = 1;
    ans.push_back(node);

    for(int j = 0; j < adj[node].size(); j++) {
        int x = adj[node][j];
        if(!visited[x]) {
            dfshelper(x, visited, adj, ans);
        }
    }
}

vector<int> depthfirst(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<int> ans;
    vector<bool> visited(V, 0);

    dfshelper(0, visited, adj, ans);
    return ans;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<vector<int>> adj(V);
    cout << "Enter edges (u v):" << endl;
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> result = depthfirst(adj);
    
    cout << "\nDFS Traversal: ";
    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}
