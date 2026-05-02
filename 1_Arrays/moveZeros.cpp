/* Move All Zeros to End Approach -
  Keep a pointer 'nonZeroIdx' to track where the next non-zero should go.
  Iterate through the array, if an element is non-zero, swap it with arr[nonZeroIdx] and increment nonZeroIdx.
*/
#include<iostream>
#include<vector>
using namespace std;

void moveZeros(vector<int>& arr) {
    int nonZeroIdx = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] != 0) {
            swap(arr[i], arr[nonZeroIdx]);
            nonZeroIdx++;
        }
    }
}

// time complexity - O(N)
int main() {
    vector<int> arr = {0, 1, 0, 3, 12};
    moveZeros(arr);
    for(int num : arr) cout << num << " ";
    return 0;
}
