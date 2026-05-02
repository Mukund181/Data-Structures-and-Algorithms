/* Bipartite Graph Approach -
  Graph can be colored using exactly 2 colors such that no adjacent nodes have same color.
  Use BFS. Color start node 0. Push to queue.
  Pop node, color all uncolored neighbors with opposite color (1 - color).
  If neighbor has same color as node, not bipartite.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);
    
    for(int i = 0; i < n; i++) {
        if(color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                
                for(int neighbor : graph[node]) {
                    if(color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    } else if(color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

// time complexity - O(V + E)
int main() {
    vector<vector<int>> graph = {{1,3}, {0,2}, {1,3}, {0,2}};
    cout << "Is Bipartite: " << isBipartite(graph) << endl;
    return 0;
}
