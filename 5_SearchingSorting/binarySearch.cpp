/* Binary Search Approach -
  Find middle element. If matches target, return index.
  If target < mid, search left half. Else search right half.
  Works only on sorted arrays.
*/
#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target) return mid;
        if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// time complexity - O(log N)
int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    cout << "Index of 7: " << binarySearch(arr, 7) << endl;
    return 0;
}
