/* Median in Data Stream Approach -
  Use two heaps: a max-heap for the lower half of data, and a min-heap for the upper half.
  Keep them balanced. The median is either the top of max-heap or avg of tops.
*/
#include<iostream>
#include<queue>
using namespace std;

class MedianFinder {
    priority_queue<int> maxHeap; // Lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Upper half
public:
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

// time complexity - O(log N) per add
int main() {
    MedianFinder mf;
    mf.addNum(1); mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl;
    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl;
    return 0;
}
