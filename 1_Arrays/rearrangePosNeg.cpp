/* Rearrange Array (Positive and Negative Alternately) Approach -
  Given an array with equal number of positive and negative numbers.
  Create an answer array. Use two pointers, posIdx starting at 0, negIdx starting at 1.
  Iterate the original array, place elements at posIdx or negIdx and increment by 2.
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> ans(nums.size(), 0);
    int posIdx = 0, negIdx = 1;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            ans[posIdx] = nums[i];
            posIdx += 2;
        } else {
            ans[negIdx] = nums[i];
            negIdx += 2;
        }
    }
    return ans;
}

// time complexity - O(N)
int main() {
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> ans = rearrangeArray(nums);
    for(int num : ans) cout << num << " ";
    return 0;
}
