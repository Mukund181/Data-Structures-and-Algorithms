/* Two Sum using HashMap Approach -
  Same as Two Sum. Store previously seen elements in hash map.
  Check if (target - current) is in hash map.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    for(int i = 0; i < nums.size(); i++) {
        if(seen.find(target - nums[i]) != seen.end()) {
            return {seen[target - nums[i]], i};
        }
        seen[nums[i]] = i;
    }
    return {};
}

// time complexity - O(N)
int main() {
    vector<int> nums = {2, 7, 11, 15};
    vector<int> res = twoSum(nums, 9);
    if(res.size() == 2) cout << "Indices: " << res[0] << ", " << res[1] << endl;
    return 0;
}
