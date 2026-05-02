/* Topological Sort Approach -
  Valid only for Directed Acyclic Graphs (DAG).
  Using Kahn's Algorithm (BFS): Calculate in-degree of all nodes.
  Push nodes with 0 in-degree to queue. Pop, add to result, and decrement in-degree of neighbors.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> topoSort(int V, vector<vector<int>>& adj) {
    vector<int> indegree(V, 0);
    for(int i = 0; i < V; i++) {
        for(int neighbor : adj[i]) indegree[neighbor]++;
    }
    
    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    
    vector<int> result;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        
        for(int neighbor : adj[node]) {
            indegree[neighbor]--;
            if(indegree[neighbor] == 0) q.push(neighbor);
        }
    }
    return result;
}

// time complexity - O(V + E)
int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    
    vector<int> res = topoSort(V, adj);
    cout << "Topological Sort: ";
    for(int node : res) cout << node << " ";
    return 0;
}
