/* Dijkstra's Algorithm Approach -
  Find shortest paths from a source to all other nodes in a graph with non-negative edge weights.
  Use a Min-Priority Queue to pick node with smallest known distance.
  Relax edges.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, 1e9);
    
    dist[src] = 0;
    pq.push({0, src});
    
    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(d > dist[node]) continue;
        
        for(auto it : adj[node]) {
            int adjNode = it.first;
            int weight = it.second;
            
            if(d + weight < dist[adjNode]) {
                dist[adjNode] = d + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    
    cout << "Distances from " << src << ": ";
    for(int i = 0; i < V; i++) cout << dist[i] << " ";
    cout << endl;
}

// time complexity - O((V + E) log V)
int main() {
    int V = 3;
    vector<vector<pair<int, int>>> adj(V);
    adj[0].push_back({1, 1});
    adj[0].push_back({2, 6});
    adj[1].push_back({2, 3});
    
    dijkstra(V, adj, 0);
    return 0;
}
