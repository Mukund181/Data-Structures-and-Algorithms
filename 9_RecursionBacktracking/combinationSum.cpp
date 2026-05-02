/* Combination Sum Approach -
  Find all unique combinations in candidates that sum up to target.
  Since we can use the same number multiple times, we stay at the same index if we pick it.
  If we don't pick it, move to next index. Backtrack to explore all paths.
*/
#include<iostream>
#include<vector>
using namespace std;

void findCombinations(int idx, int target, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans) {
    if(idx == arr.size()) {
        if(target == 0) ans.push_back(ds);
        return;
    }
    
    // Pick the element
    if(arr[idx] <= target) {
        ds.push_back(arr[idx]);
        findCombinations(idx, target - arr[idx], arr, ds, ans);
        ds.pop_back(); // backtrack
    }
    
    // Don't pick the element
    findCombinations(idx + 1, target, arr, ds, ans);
}

// time complexity - O(2^T * k) where T is target, k is avg length
int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> ans;
    vector<int> ds;
    
    findCombinations(0, target, candidates, ds, ans);
    for(auto comb : ans) {
        for(int x : comb) cout << x << " ";
        cout << "| ";
    }
    return 0;
}
