/* Search in Rotated Sorted Array Approach -
  Use Binary Search. One half will always be sorted.
  Check which half is sorted, then check if target falls in the range of that sorted half.
  If yes, search that half, else search the other half.
*/
#include<iostream>
#include<vector>
using namespace std;

int searchRotated(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;
        
        // Left half is sorted
        if(nums[left] <= nums[mid]) {
            if(target >= nums[left] && target < nums[mid]) right = mid - 1;
            else left = mid + 1;
        } 
        // Right half is sorted
        else {
            if(target > nums[mid] && target <= nums[right]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
}

// time complexity - O(log N)
int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << "Index of 0: " << searchRotated(nums, 0) << endl;
    return 0;
}
