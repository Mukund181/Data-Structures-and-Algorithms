/* Remove Duplicates from Sorted Array Approach -
  Use a pointer 'i' to track the position of unique elements.
  Iterate 'j' through the array. If arr[j] != arr[i], it's a new unique element.
  Increment 'i' and copy arr[j] to arr[i].
*/
#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& arr) {
    if(arr.empty()) return 0;
    int i = 0;
    for(int j = 1; j < arr.size(); j++) {
        if(arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1; // number of unique elements
}

// time complexity - O(N)
int main() {
    vector<int> arr = {1, 1, 2, 2, 2, 3, 4, 4};
    int k = removeDuplicates(arr);
    for(int i = 0; i < k; i++) cout << arr[i] << " ";
    return 0;
}
