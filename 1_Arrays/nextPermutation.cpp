/* Next Permutation Approach -
  1. Find the first index 'idx' from the right where nums[idx] < nums[idx+1].
  2. If no such index exists, reverse the entire array.
  3. Else, find the smallest element to the right of 'idx' which is > nums[idx].
  4. Swap them and reverse the right half.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int idx = -1;
    int n = nums.size();
    
    // Step 1
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        reverse(nums.begin(), nums.end()); // Step 2
    } else {
        // Step 3
        for (int i = n - 1; i > idx; i--) {
            if (nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]); // Step 4
                break;
            }
        }
        reverse(nums.begin() + idx + 1, nums.end());
    }
}

// time complexity - O(N)
int main() {
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);
    for(int num : nums) cout << num << " ";
    return 0;
}
