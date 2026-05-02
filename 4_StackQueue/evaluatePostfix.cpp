/* Evaluate Postfix Expression Approach -
  Use a stack. Iterate over the expression.
  If operand, push to stack.
  If operator, pop two elements, perform operation, push result.
*/
#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for(string& token : tokens) {
        if(token == "+" || token == "-" || token == "*" || token == "/") {
            int op2 = st.top(); st.pop();
            int op1 = st.top(); st.pop();
            if(token == "+") st.push(op1 + op2);
            else if(token == "-") st.push(op1 - op2);
            else if(token == "*") st.push(op1 * op2);
            else if(token == "/") st.push(op1 / op2);
        } else {
            st.push(stoi(token));
        }
    }
    return st.top();
}

// time complexity - O(N)
int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << "Result: " << evalRPN(tokens) << endl;
    return 0;
}
