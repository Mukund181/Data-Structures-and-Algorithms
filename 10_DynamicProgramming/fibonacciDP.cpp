/* Fibonacci DP Approach -
  Memoization: Store already computed Fibonacci numbers in an array.
  Tabulation: Compute iteratively from bottom up.
*/
#include<iostream>
#include<vector>
using namespace std;

// Tabulation
int fibDP(int n) {
    if(n <= 1) return n;
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// time complexity - O(N), Space - O(N)
int main() {
    cout << "Fib 6 (DP): " << fibDP(6) << endl;
    return 0;
}
