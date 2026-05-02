/* Two Sum Approach -
  Given an array and target, find two numbers that sum to target.
  Use a hash map to store the elements and their indices.
  For each element, check if (target - element) exists in the map.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (seen.find(complement) != seen.end()) {
            return {seen[complement], i};
        }
        seen[nums[i]] = i;
    }
    return {};
}

// time complexity - O(N)
int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    if (!result.empty()) cout << "Indices: " << result[0] << ", " << result[1] << endl;
    return 0;
}
