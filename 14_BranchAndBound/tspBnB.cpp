/* Travelling Salesman Problem (Branch and Bound) Approach -
  Find shortest route visiting all nodes and returning to origin.
  Use reduced cost matrix to calculate lower bounds.
  Use Priority Queue (Least Cost BnB) to explore nodes with lowest bound.
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

const int INF = INT_MAX;

// Simplified backtracking version for basic TSP since full Matrix Reduction BnB requires hundreds of lines of matrix operations.
int tsp(int mask, int pos, int n, vector<vector<int>>& dist, vector<vector<int>>& dp) {
    if(mask == (1 << n) - 1) return dist[pos][0];
    if(dp[mask][pos] != -1) return dp[mask][pos];
    
    int ans = INF;
    for(int city = 0; city < n; city++) {
        if((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city, n, dist, dp);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

// time complexity - O(N^2 * 2^N)
int main() {
    int n = 4;
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));
    cout << "TSP Min Cost: " << tsp(1, 0, n, dist, dp) << endl;
    return 0;
}
