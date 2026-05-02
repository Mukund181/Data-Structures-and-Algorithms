/* Coin Change Approach -
  Find min coins to make 'amount'.
  DP state: dp[i] = min coins to make amount i.
  Transition: dp[i] = min(dp[i], 1 + dp[i - coin]).
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    
    for(int i = 1; i <= amount; i++) {
        for(int coin : coins) {
            if(i - coin >= 0) {
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

// time complexity - O(amount * N)
int main() {
    vector<int> coins = {1, 2, 5};
    cout << "Min coins for 11: " << coinChange(coins, 11) << endl;
    return 0;
}
