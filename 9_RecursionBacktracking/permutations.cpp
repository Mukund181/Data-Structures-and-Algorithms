/* Permutations Approach -
  Generate all permutations of an array/string.
  Swap current element with every other element, recurse, then backtrack (swap back).
*/
#include<iostream>
#include<vector>
using namespace std;

void permute(int idx, vector<int>& nums, vector<vector<int>>& ans) {
    if(idx == nums.size()) {
        ans.push_back(nums);
        return;
    }
    for(int i = idx; i < nums.size(); i++) {
        swap(nums[idx], nums[i]);
        permute(idx + 1, nums, ans);
        swap(nums[idx], nums[i]); // backtrack
    }
}

// time complexity - O(N! * N)
int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    permute(0, nums, ans);
    
    for(auto p : ans) {
        for(int x : p) cout << x << " ";
        cout << "| ";
    }
    return 0;
}
