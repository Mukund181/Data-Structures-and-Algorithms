/* House Robber Approach -
  Rob max money without adjacent houses.
  DP state: dp[i] = max money up to house i.
  Transition: dp[i] = max(dp[i-1], nums[i] + dp[i-2]).
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    if(n == 1) return nums[0];
    
    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);
    
    for(int i = 2; i < n; i++) {
        int curr = max(prev1, nums[i] + prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

// time complexity - O(N)
int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << "Max money robbed: " << rob(nums) << endl;
    return 0;
}
