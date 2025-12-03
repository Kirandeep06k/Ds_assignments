#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj) {
    int V = adj.size();
    queue<int> q;
    vector<int> ans;
    vector<bool> visited(V, 0);

    q.push(0);           
    visited[0] = 1;   

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        //Another way to write the loop
        // for(int x : adj[node]) {
        //     if(!visited[x]) {
        //         visited[x] = 1;
        //         q.push(x);
        //     }
        //}
        for(int j=0; j<adj[node].size(); j++) {
            int x = adj[node][j];
            if(!visited[x]) {
                visited[x] = 1;
                q.push(x);
            }
        }
    }
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

    vector<int> result = bfs(adj);

    cout << "\nBFS Traversal: ";
    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}
