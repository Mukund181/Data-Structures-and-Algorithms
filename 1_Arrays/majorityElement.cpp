/* Majority Element (Boyer-Moore Voting Algorithm) Approach -
  Find the element that appears more than N/2 times.
  Maintain a count and a candidate.
  If count == 0, candidate = current element.
  If current == candidate, count++. Else count--.
*/
#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }
    return candidate; // Assuming majority element always exists
}

// time complexity - O(N)
int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element: " << majorityElement(nums) << endl;
    return 0;
}
