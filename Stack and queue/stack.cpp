// with and without stl tutorial
#include<iostream>
#include<stack>
using namespace std;

class stk {
   public :
   int top;
   int st[10];
   stk(){
    top=-1;
   }
   void push(int d){
    if(top==10){
        return;
    }
    st[++top]=d;
   }
   int pop(){
    if(top==-1) return -1;
    return st[top--];
   }
   int peek(){
    return st[top];
   }
};

int main(){
    //stl
    stack<int> st;
    st.push(10);
    st.push(12);
    st.push(8);
    cout<<"Stack top : "<<st.top()<<endl;
    st.pop();
    cout<<"New size : "<<st.size()<<endl;
    // without stl
    stk s;
    s.push(40);
    s.push(30);
    s.push(98);
    cout<<s.pop()<<endl;
    cout<<s.peek();
}