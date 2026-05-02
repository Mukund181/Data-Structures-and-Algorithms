/* DFS Traversal Approach -
  Use Recursion (Call Stack).
  Mark current node as visited, process it.
  Recursively call DFS for all unvisited neighbors.
*/
#include<iostream>
#include<vector>
using namespace std;

void dfsUtil(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            dfsUtil(neighbor, adj, visited);
        }
    }
}

void dfs(int startNode, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    cout << "DFS: ";
    dfsUtil(startNode, adj, visited);
    cout << endl;
}

// time complexity - O(V + E)
int main() {
    vector<vector<int>> adj = {{1, 2}, {0, 3, 4}, {0, 4}, {1, 5}, {1, 2, 5}, {3, 4}};
    dfs(0, adj);
    return 0;
}
