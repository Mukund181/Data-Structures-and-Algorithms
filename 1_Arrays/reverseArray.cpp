/* Reverse an Array Approach -
  Use two pointers, one at the start and one at the end of the array.
  Swap the elements at these pointers and move them towards the center.
  Stop when start >= end.
*/
#include<iostream>
#include<vector>
using namespace std;

void reverseArray(vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;
    
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// time complexity - O(N)
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    reverseArray(arr);
    for(int num : arr) cout << num << " ";
    return 0;
}
