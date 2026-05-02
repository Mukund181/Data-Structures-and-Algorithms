/* Trapping Rain Water Approach -
  Use two pointers, left and right. Maintain maxLeft and maxRight.
  If height[left] <= height[right], process left:
    If height[left] >= maxLeft, update maxLeft.
    Else, add maxLeft - height[left] to trapped water. Move left++.
  Else process right similarly.
*/
#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;
    int left = 0, right = n - 1;
    int res = 0;
    int maxLeft = 0, maxRight = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= maxLeft) maxLeft = height[left];
            else res += maxLeft - height[left];
            left++;
        } else {
            if (height[right] >= maxRight) maxRight = height[right];
            else res += maxRight - height[right];
            right--;
        }
    }
    return res;
}

// time complexity - O(N)
int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Trapped Water: " << trap(height) << endl;
    return 0;
}
