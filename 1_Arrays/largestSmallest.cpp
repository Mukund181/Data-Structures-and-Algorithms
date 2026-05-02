/* Find Largest and Smallest Element Approach -
  Initialize largest and smallest with the first element of the array.
  Iterate through the array.
  If current element > largest, update largest.
  If current element < smallest, update smallest.
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void findLargestSmallest(vector<int>& arr) {
    if(arr.empty()) return;
    int largest = arr[0];
    int smallest = arr[0];
    
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] > largest) largest = arr[i];
        if(arr[i] < smallest) smallest = arr[i];
    }
    cout << "Largest: " << largest << ", Smallest: " << smallest << endl;
}

// time complexity - O(N)
int main() {
    vector<int> arr = {4, 7, 2, 9, 1, 5, 8};
    findLargestSmallest(arr);
    return 0;
}
