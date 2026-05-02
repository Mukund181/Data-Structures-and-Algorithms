/* BFS Traversal Approach -
  Use a Queue. Start from an initial node, push to queue, mark visited.
  While queue not empty, pop node, process it, push all unvisited neighbors.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int startNode, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;
    
    q.push(startNode);
    visited[startNode] = true;
    
    cout << "BFS: ";
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        
        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

// time complexity - O(V + E)
int main() {
    vector<vector<int>> adj = {{1, 2}, {0, 3, 4}, {0, 4}, {1, 5}, {1, 2, 5}, {3, 4}};
    bfs(0, adj);
    return 0;
}
