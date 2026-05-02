/* Valid Parentheses Approach -
  Use a Stack. Iterate through string.
  If opening bracket, push to stack.
  If closing bracket, check if it matches the top of stack. If yes, pop.
  At end, stack must be empty.
*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for(char c : s) {
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if(st.empty()) return false;
            char top = st.top();
            if((c == ')' && top == '(') || 
               (c == '}' && top == '{') || 
               (c == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

// time complexity - O(N)
int main() {
    cout << "is valid '()[]{}': " << isValid("()[]{}") << endl;
    cout << "is valid '(]': " << isValid("(]") << endl;
    return 0;
}
