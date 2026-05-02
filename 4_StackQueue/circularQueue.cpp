/* Circular Queue Approach -
  Use an array and two pointers: front and rear.
  Use modulo arithmetic (index % capacity) to wrap around the array.
*/
#include<iostream>
#include<vector>
using namespace std;

class MyCircularQueue {
    vector<int> q;
    int head = 0, tail = -1, size = 0, capacity;
public:
    MyCircularQueue(int k) {
        capacity = k;
        q.resize(k);
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        tail = (tail + 1) % capacity;
        q[tail] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % capacity;
        size--;
        return true;
    }
    
    int Front() { return isEmpty() ? -1 : q[head]; }
    int Rear() { return isEmpty() ? -1 : q[tail]; }
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == capacity; }
};

// time complexity - O(1) for all ops
int main() {
    MyCircularQueue cq(3);
    cq.enQueue(1); cq.enQueue(2); cq.enQueue(3);
    cout << "Is Full: " << cq.isFull() << endl;
    cq.deQueue();
    cq.enQueue(4);
    cout << "Rear: " << cq.Rear() << endl;
    return 0;
}
