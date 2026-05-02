/* Implement Queue using Stacks Approach -
  Use two stacks: s1 for input, s2 for output.
  Push operation: simply push to s1.
  Pop/Peek operation: if s2 is empty, transfer all from s1 to s2, then pop/peek from s2.
*/
#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
    stack<int> s1, s2;
public:
    void push(int x) { s1.push(x); }
    
    int pop() {
        int val = peek();
        s2.pop();
        return val;
    }
    
    int peek() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() { return s1.empty() && s2.empty(); }
};

// time complexity - Amortized O(1) for pop/peek
int main() {
    MyQueue q;
    q.push(1); q.push(2);
    cout << "Peek: " << q.peek() << endl;
    cout << "Pop: " << q.pop() << endl;
    cout << "Empty: " << q.empty() << endl;
    return 0;
}
