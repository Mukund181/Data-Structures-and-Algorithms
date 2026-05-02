/* Maximum Product Subarray Approach -
  Keep track of both the max product and min product up to the current element.
  If the current element is negative, min product could become max product when multiplied.
  Swap max product and min product when encountering a negative number.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;

    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int tempMax = maxProd;
        maxProd = max({nums[i], maxProd * nums[i], minProd * nums[i]});
        minProd = min({nums[i], tempMax * nums[i], minProd * nums[i]});
        result = max(result, maxProd);
    }
    return result;
}

// time complexity - O(N)
int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << "Max Product Subarray: " << maxProduct(nums) << endl;
    return 0;
}
