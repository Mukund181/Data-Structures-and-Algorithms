/* Find Peak Element Approach -
  A peak is strictly greater than its neighbors.
  Use Binary Search. If mid element < mid+1 element, peak is on the right.
  Else peak is on the left (including mid).
*/
#include<iostream>
#include<vector>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] < nums[mid + 1]) {
            left = mid + 1; // Peak is in right half
        } else {
            right = mid; // Peak is in left half or is mid
        }
    }
    return left; // or right
}

// time complexity - O(log N)
int main() {
    vector<int> nums = {1,2,1,3,5,6,4};
    cout << "Peak Index: " << findPeakElement(nums) << endl;
    return 0;
}
