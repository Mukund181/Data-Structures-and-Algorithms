/* Detect Cycle in Graph Approach -
  Undirected Graph using BFS/DFS: If we reach an already visited node that is NOT the parent, there's a cycle.
  Directed Graph using DFS: If we reach a node that is currently in the recursion stack, there's a cycle.
  (Implemented here: Undirected using BFS)
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool detectCycleBFS(int src, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[src] = true;
    queue<pair<int, int>> q; // {node, parent}
    q.push({src, -1});
    
    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for(auto neighbor : adj[node]) {
            if(!vis[neighbor]) {
                vis[neighbor] = true;
                q.push({neighbor, node});
            } else if(neighbor != parent) {
                return true; // Cycle detected
            }
        }
    }
    return false;
}

// time complexity - O(V + E)
int main() {
    int n = 5;
    vector<vector<int>> adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    vector<bool> vis(n, false);
    
    bool hasCycle = false;
    for(int i = 0; i < n; i++) {
        if(!vis[i] && detectCycleBFS(i, adj, vis)) {
            hasCycle = true;
            break;
        }
    }
    cout << "Has Cycle: " << hasCycle << endl;
    return 0;
}
