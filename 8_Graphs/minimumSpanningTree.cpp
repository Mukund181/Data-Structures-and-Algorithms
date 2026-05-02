/* Minimum Spanning Tree (Prim's Algorithm) Approach -
  Greedily pick the smallest edge that connects a visited node to an unvisited node.
  Use a Min-Priority Queue. Store {weight, node}.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int spanningTree(int V, vector<vector<pair<int, int>>>& adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> vis(V, false);
    
    int sum = 0;
    pq.push({0, 0}); // {weight, node}
    
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        
        if(vis[node]) continue;
        
        vis[node] = true;
        sum += wt;
        
        for(auto neighbor : adj[node]) {
            int adjNode = neighbor.first;
            int edW = neighbor.second;
            if(!vis[adjNode]) {
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
}

// time complexity - O(E log V)
int main() {
    int V = 3;
    vector<vector<pair<int, int>>> adj(V);
    adj[0].push_back({1, 5}); adj[1].push_back({0, 5});
    adj[1].push_back({2, 3}); adj[2].push_back({1, 3});
    adj[0].push_back({2, 1}); adj[2].push_back({0, 1});
    
    cout << "MST Sum: " << spanningTree(V, adj) << endl;
    return 0;
}
