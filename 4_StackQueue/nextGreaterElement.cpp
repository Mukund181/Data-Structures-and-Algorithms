/* Next Greater Element Approach -
  Iterate array from right to left.
  Maintain a stack of elements.
  Pop elements from stack while they are <= current element.
  If stack is empty, next greater is -1. Else it is stack top.
  Push current element to stack.
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;

    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        if(!st.empty()) {
            res[i] = st.top();
        }
        st.push(nums[i]);
    }
    return res;
}

// time complexity - O(N)
int main() {
    vector<int> nums = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    vector<int> res = nextGreaterElement(nums);
    for(int r : res) cout << r << " ";
    return 0;
}
