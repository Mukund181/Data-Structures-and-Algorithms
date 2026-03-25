#include<iostream>
#include<stack>
#include<string>
using namespace std;

string reverseStr(string s){
    stack<char>st;
    for(int i=0;i<s.size();i++){
        st.push(s[i]);
    }
    s.clear();
    while(!st.empty()){
        s.push_back(st.top());
        st.pop();
    }

    return s;
}

int main(){
    string s = "Mukund";
    cout<<reverseStr(s);
}