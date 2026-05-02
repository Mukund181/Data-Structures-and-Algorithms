/* Sliding Window Maximum Approach -
  Use a deque to store indices of array elements.
  Maintain deque in decreasing order of values.
  Remove elements from front if they fall out of window.
  Remove elements from back if they are smaller than current element.
*/
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> res;
    for(int i = 0; i < nums.size(); i++) {
        if(!dq.empty() && dq.front() == i - k) dq.pop_front();
        
        while(!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k - 1) res.push_back(nums[dq.front()]);
    }
    return res;
}

// time complexity - O(N)
int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = maxSlidingWindow(nums, k);
    for(int r : res) cout << r << " ";
    return 0;
}
