/* 0/1 Knapsack Approach -
  Given weights and values of n items, and a knapsack capacity W.
  DP state: dp[i][w] = max value using first i items and capacity w.
  Transition: max(pick item, don't pick item).
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int knapsack(vector<int>& val, vector<int>& wt, int W, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= W; w++) {
            if(wt[i-1] <= w) {
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

// time complexity - O(N * W)
int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    cout << "Max Knapsack Value: " << knapsack(val, wt, W, 3) << endl;
    return 0;
}
