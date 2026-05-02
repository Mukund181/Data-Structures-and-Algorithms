/* Longest Increasing Subsequence Approach -
  Find length of longest strictly increasing subsequence.
  DP state: dp[i] = length of LIS ending at i.
  Transition: For j < i, if nums[j] < nums[i], dp[i] = max(dp[i], 1 + dp[j]).
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if(nums.empty()) return 0;
    vector<int> dp(nums.size(), 1);
    int maxLIS = 1;
    
    for(int i = 1; i < nums.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        maxLIS = max(maxLIS, dp[i]);
    }
    return maxLIS;
}

// time complexity - O(N^2), can be optimized to O(N log N) with Binary Search
int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "LIS Length: " << lengthOfLIS(nums) << endl;
    return 0;
}
