/* Check if Array is Sorted Approach -
  Iterate from the second element to the end.
  If any element is smaller than its previous element, the array is not sorted.
*/
#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int>& arr) {
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] < arr[i - 1]) return false;
    }
    return true;
}

// time complexity - O(N)
int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 3, 2, 4, 5};
    cout << "arr1 sorted: " << (isSorted(arr1) ? "Yes" : "No") << endl;
    cout << "arr2 sorted: " << (isSorted(arr2) ? "Yes" : "No") << endl;
    return 0;
}
