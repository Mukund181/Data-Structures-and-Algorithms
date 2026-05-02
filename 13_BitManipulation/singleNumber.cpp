/* Single Number Approach -
  Every element appears twice except one.
  XOR of a number with itself is 0. XOR of all elements leaves the single number.
*/
#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int res = 0;
    for(int num : nums) res ^= num;
    return res;
}

// time complexity - O(N)
int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "Single Number: " << singleNumber(nums) << endl;
    return 0;
}
