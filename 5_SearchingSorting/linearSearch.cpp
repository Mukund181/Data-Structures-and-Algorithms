/* Linear Search Approach -
  Iterate through the array.
  Compare each element with target. Return index if found.
*/
#include<iostream>
#include<vector>
using namespace std;

int linearSearch(vector<int>& arr, int target) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == target) return i;
    }
    return -1;
}

// time complexity - O(N)
int main() {
    vector<int> arr = {4, 2, 8, 1, 9};
    cout << "Index of 8: " << linearSearch(arr, 8) << endl;
    return 0;
}
