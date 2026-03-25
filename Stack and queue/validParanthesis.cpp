#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool checkParanthesis(string s){
    stack<char> st;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(!st.empty() && st.top() == '('){
                st.pop();
            }
            else{
                return false;
            }
        }
    }

    return st.empty();
}

int main(){
    string s = "(())()";
    cout << checkParanthesis(s) << endl;   // 1

    string str = "(()))";
    cout << checkParanthesis(str) << endl; // 0

    string s2 = ")(";
    cout << checkParanthesis(s2);          // 0
}