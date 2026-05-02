/* Subarray with Given Sum Approach -
  Use Hash Map to store (prefix_sum, index).
  If prefix_sum == target, subarray starts from 0.
  If (prefix_sum - target) is in hash map, subarray is from (hash_map_index + 1) to current.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    map[0] = 1; // base case
    int sum = 0, count = 0;
    
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if(map.find(sum - k) != map.end()) {
            count += map[sum - k];
        }
        map[sum]++;
    }
    return count;
}

// time complexity - O(N)
int main() {
    vector<int> nums = {1, 1, 1};
    cout << "Subarrays with sum 2: " << subarraySum(nums, 2) << endl;
    return 0;
}
