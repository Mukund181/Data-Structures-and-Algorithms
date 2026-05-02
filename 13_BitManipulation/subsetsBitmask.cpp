/* Subsets using Bitmask Approach -
  For array of size N, there are 2^N subsets.
  Numbers 0 to (2^N - 1) represent all possible inclusion/exclusion states.
  If j-th bit is set in i, include arr[j] in the i-th subset.
*/
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int subsetCount = (1 << n); // 2^N
    vector<vector<int>> ans;
    
    for(int i = 0; i < subsetCount; i++) {
        vector<int> sub;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                sub.push_back(nums[j]);
            }
        }
        ans.push_back(sub);
    }
    return ans;
}

// time complexity - O(N * 2^N)
int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);
    for(auto sub : ans) {
        cout << "{ ";
        for(int x : sub) cout << x << " ";
        cout << "} ";
    }
    return 0;
}
