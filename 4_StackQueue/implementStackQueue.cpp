/* Implement Stack and Queue Approach -
  Stack using Array/Vector (LIFO - Last In First Out).
  Queue using Array/Vector (FIFO - First In First Out).
*/
#include<iostream>
#include<vector>
using namespace std;

class MyStack {
    vector<int> arr;
public:
    void push(int x) { arr.push_back(x); }
    int pop() {
        if(arr.empty()) return -1;
        int val = arr.back();
        arr.pop_back();
        return val;
    }
    int top() { return arr.empty() ? -1 : arr.back(); }
    bool isEmpty() { return arr.empty(); }
};

class MyQueue {
    vector<int> arr;
    int frontIdx = 0;
public:
    void push(int x) { arr.push_back(x); }
    int pop() {
        if(frontIdx >= arr.size()) return -1;
        return arr[frontIdx++];
    }
    int peek() { return frontIdx >= arr.size() ? -1 : arr[frontIdx]; }
    bool isEmpty() { return frontIdx >= arr.size(); }
};

// time complexity - O(1) for push, pop, top, peek
int main() {
    MyStack st;
    st.push(10); st.push(20);
    cout << "Stack pop: " << st.pop() << endl;

    MyQueue q;
    q.push(1); q.push(2);
    cout << "Queue pop: " << q.pop() << endl;
    return 0;
}
