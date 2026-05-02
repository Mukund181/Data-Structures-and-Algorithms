/* Left Rotate Array by 1 Approach -
  Store the first element in a temp variable.
  Shift all elements from index 1 to n-1 one position to the left.
  Place the temp variable at the last index.
*/
#include<iostream>
#include<vector>
using namespace std;

void leftRotateByOne(vector<int>& arr) {
    if(arr.empty()) return;
    int temp = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        arr[i - 1] = arr[i];
    }
    arr[arr.size() - 1] = temp;
}

// time complexity - O(N)
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    leftRotateByOne(arr);
    for(int num : arr) cout << num << " ";
    return 0;
}
