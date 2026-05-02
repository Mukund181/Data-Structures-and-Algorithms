/* Kadane's Algorithm Approach -
  Find the contiguous subarray with the maximum sum.
  Keep track of current sum. If current sum becomes < 0, reset it to 0.
  Continuously update the maximum sum encountered so far.
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN;
    int currSum = 0;

    for (int num : nums) {
        currSum += num;
        if (currSum > maxSum) {
            maxSum = currSum;
        }
        if (currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
}

// time complexity - O(N)
int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Max Subarray Sum: " << maxSubArray(nums) << endl;
    return 0;
}
