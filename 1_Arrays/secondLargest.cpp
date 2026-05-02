/* Find Second Largest Element Approach -
  Initialize largest and secondLargest.
  Iterate through the array.
  If element > largest, update secondLargest to largest, and largest to element.
  If element > secondLargest and element != largest, update secondLargest.
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int secondLargest(vector<int>& arr) {
    int largest = INT_MIN;
    int second = INT_MIN;
    
    for(int num : arr) {
        if(num > largest) {
            second = largest;
            largest = num;
        } else if(num > second && num != largest) {
            second = num;
        }
    }
    return second == INT_MIN ? -1 : second; // -1 if no second largest exists
}

// time complexity - O(N)
int main() {
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    cout << "Second Largest: " << secondLargest(arr) << endl;
    return 0;
}
