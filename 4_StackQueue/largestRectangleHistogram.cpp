/* Largest Rectangle in Histogram Approach -
  Use a stack to keep track of indices of increasing heights.
  When a smaller height is found, pop from stack, calculate area with popped height.
  Width is (current index - new stack top - 1).
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0, n = heights.size();
    
    for(int i = 0; i <= n; i++) {
        while(!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
            int h = heights[st.top()];
            st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        st.push(i);
    }
    return maxArea;
}

// time complexity - O(N)
int main() {
    vector<int> heights = {2,1,5,6,2,3};
    cout << "Max Area: " << largestRectangleArea(heights) << endl;
    return 0;
}
