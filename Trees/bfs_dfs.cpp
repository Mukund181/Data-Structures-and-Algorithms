#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void bfs(int graph[4][4],int visited[],int start,int goal){
    // breadth first search --> visit all adjacent neighbours before proceeding further (level by level)
    // using queue 
    int n = 4;  
    queue<int>q;
    q.push(start);
    visited[start]=1;
    while(!q.empty()){
        int node = q.front();
        cout<<node<<" ";
        q.pop();
        if(node==goal) return;
        for(int i=0;i<n;i++){ // for iterating throiugh neighbbours of node
            if(graph[node][i] && !visited[i]){ // if there is a edge from the current node(finding neighbours) and its not visited
                visited[i]=1;  
                q.push(i);
            }
        }
    }
}
void dfs(vector<vector<int>>graph,vector<int>traversed,int start,int goal){
    // depth first search --> explore as deep as possible before backtracking (branch wise)
    // bfs preferred for shortest paths , dfs for finding far away paths while saving memory
    stack<int>s;
    int n=traversed.size();
    s.push(start);
    traversed[start]=1;
    while(!s.empty()){
        int node = s.top();
        cout<<node<<" ";
        s.pop();
        if(start==goal) return;
        for(int i=n-1;i>=0;i--){  // go on putting all neighbours from back(to visit them later on)
            // so that nearest will come at top and we can explore its neighbour before previous node neighbours still in stack
            if(graph[node][i] && !traversed[i]){
               traversed[i]=1;
               s.push(i);
            }
        }
    }
}
int main(){
    // adjacency matrix rep of undirected graph
    int graph[4][4]={{0,1,1,0},{1,0,0,1},{1,0,0,0},{0,1,0,0}};
    int visited[4]={0};
    bfs(graph,visited,0,3);
    cout<<endl;
    vector<vector<int>>g = {{0,1,1,0},{1,0,0,1},{1,0,0,0},{0,1,0,0}};
    vector<int>traversed(4,0);
    dfs(g,traversed,0,3);
}