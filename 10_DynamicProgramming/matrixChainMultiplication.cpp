/* Matrix Chain Multiplication Approach -
  Find the most efficient way to multiply matrices.
  DP state: dp[i][j] = min cost to multiply matrices from i to j.
  Transition: Try all partitions k. dp[i][j] = min(dp[i][k] + dp[k+1][j] + cost).
*/
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int matrixMultiplication(int N, vector<int>& arr) {
    vector<vector<int>> dp(N, vector<int>(N, 0));
    
    for(int len = 2; len < N; len++) {
        for(int i = 1; i < N - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for(int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][N-1];
}

// time complexity - O(N^3)
int main() {
    vector<int> arr = {10, 20, 30, 40, 30};
    cout << "Min cost MCM: " << matrixMultiplication(5, arr) << endl;
    return 0;
}
