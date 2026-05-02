/* Min Stack Approach -
  Use a stack of pairs: {value, current_minimum}.
  On push, new min is min(value, current top min).
*/
#include<iostream>
#include<stack>
using namespace std;

class MinStack {
    stack<pair<int, int>> st;
public:
    void push(int val) {
        if(st.empty()) st.push({val, val});
        else st.push({val, min(val, st.top().second)});
    }
    void pop() {
        if(!st.empty()) st.pop();
    }
    int top() {
        return st.top().first;
    }
    int getMin() {
        return st.top().second;
    }
};

// time complexity - O(1) for all operations
int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Min: " << minStack.getMin() << endl; // Returns -3
    minStack.pop();
    cout << "Min: " << minStack.getMin() << endl; // Returns -2
    return 0;
}
