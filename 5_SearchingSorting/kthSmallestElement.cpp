/* Kth Smallest Element Approach -
  Use a Max-Heap of size K.
  Insert elements. If heap size > K, pop.
  The top element will be the Kth smallest.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int kthSmallest(vector<int>& arr, int k) {
    priority_queue<int> maxHeap;
    for(int num : arr) {
        maxHeap.push(num);
        if(maxHeap.size() > k) maxHeap.pop();
    }
    return maxHeap.top();
}

// time complexity - O(N log K)
int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << "3rd Smallest: " << kthSmallest(arr, k) << endl;
    return 0;
}
