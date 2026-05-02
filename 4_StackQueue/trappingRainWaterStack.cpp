/* Trapping Rain Water (Stack version) Approach -
  Use a stack to store indices of bars.
  If current bar > bar at stack top, it means a valley is formed.
  Pop the valley, calculate trapped water using min(current, new stack top) - valley.
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int trapStack(vector<int>& height) {
    stack<int> st;
    int res = 0;
    
    for(int i = 0; i < height.size(); i++) {
        while(!st.empty() && height[i] > height[st.top()]) {
            int valleyIdx = st.top();
            st.pop();
            if(st.empty()) break;
            
            int leftBound = st.top();
            int h = min(height[i], height[leftBound]) - height[valleyIdx];
            int w = i - leftBound - 1;
            res += h * w;
        }
        st.push(i);
    }
    return res;
}

// time complexity - O(N)
int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped: " << trapStack(height) << endl;
    return 0;
}
