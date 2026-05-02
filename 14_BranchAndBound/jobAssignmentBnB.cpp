/* Job Assignment using Priority Queue (Least Cost BnB) Approach -
  Assign N jobs to N workers such that total cost is minimized.
  State space tree: Level = worker, Branch = job.
  Bound = Cost so far + min cost of remaining jobs for unassigned workers.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

struct Node {
    int cost, workerID;
    vector<bool> assigned;
    bool operator>(const Node& other) const { return cost > other.cost; }
};

int findMinCost(int worker, vector<vector<int>>& costMatrix, vector<bool>& assigned, int n) {
    if(worker == n) return 0;
    int minC = INT_MAX;
    for(int j=0; j<n; j++) {
        if(!assigned[j]) minC = min(minC, costMatrix[worker][j]);
    }
    return minC + findMinCost(worker+1, costMatrix, assigned, n);
}

int solveJobAssignment(int n, vector<vector<int>>& costMatrix) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    Node root = {0, -1, vector<bool>(n, false)};
    pq.push(root);
    int minCost = INT_MAX;
    
    while(!pq.empty()) {
        Node u = pq.top(); pq.pop();
        if(u.workerID == n - 1) {
            minCost = min(minCost, u.cost);
            continue;
        }
        
        int nextWorker = u.workerID + 1;
        for(int j=0; j<n; j++) {
            if(!u.assigned[j]) {
                Node v = u;
                v.workerID = nextWorker;
                v.assigned[j] = true;
                v.cost += costMatrix[nextWorker][j];
                // basic bound check
                if(v.cost < minCost) pq.push(v);
            }
        }
    }
    return minCost;
}

// time complexity - Exponential worst case
int main() {
    int n = 4;
    vector<vector<int>> costMatrix = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };
    cout << "Min Cost Job Assignment: " << solveJobAssignment(n, costMatrix) << endl;
    return 0;
}
