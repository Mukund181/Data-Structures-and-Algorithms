/* Kosaraju's Algorithm (SCC) Approach -
  Finds Strongly Connected Components.
  1. DFS to find finish times (push to stack).
  2. Reverse the graph edges.
  3. Pop from stack and do DFS on reversed graph. Each DFS call gives one SCC.
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
    vis[node] = true;
    for(int it : adj[node]) {
        if(!vis[it]) dfs(it, adj, vis, st);
    }
    st.push(node);
}

void dfsRev(int node, vector<vector<int>>& adjRev, vector<bool>& vis) {
    vis[node] = true;
    cout << node << " ";
    for(int it : adjRev[node]) {
        if(!vis[it]) dfsRev(it, adjRev, vis);
    }
}

void kosaraju(int V, vector<vector<int>>& adj) {
    vector<bool> vis(V, false);
    stack<int> st;
    for(int i=0; i<V; i++) {
        if(!vis[i]) dfs(i, adj, vis, st);
    }
    
    vector<vector<int>> adjRev(V);
    for(int i=0; i<V; i++) {
        vis[i] = false;
        for(int it : adj[i]) {
            adjRev[it].push_back(i);
        }
    }
    
    int sccCount = 0;
    while(!st.empty()) {
        int node = st.top(); st.pop();
        if(!vis[node]) {
            sccCount++;
            cout << "SCC " << sccCount << ": ";
            dfsRev(node, adjRev, vis);
            cout << endl;
        }
    }
}

// time complexity - O(V + E)
int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0].push_back(2); adj[2].push_back(1); adj[1].push_back(0);
    adj[0].push_back(3); adj[3].push_back(4);
    kosaraju(V, adj);
    return 0;
}
