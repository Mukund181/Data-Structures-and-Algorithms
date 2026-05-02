/* Print All Subsequences Approach -
  For every element, we have 2 choices: either include it in the subsequence or don't.
  Explore both paths using recursion.
*/
#include<iostream>
#include<vector>
using namespace std;

void printSubsequences(int idx, vector<int>& arr, vector<int>& ds) {
    if(idx == arr.size()) {
        for(int x : ds) cout << x << " ";
        if(ds.empty()) cout << "{}";
        cout << endl;
        return;
    }
    // Include element
    ds.push_back(arr[idx]);
    printSubsequences(idx + 1, arr, ds);
    ds.pop_back();
    
    // Don't include element
    printSubsequences(idx + 1, arr, ds);
}

// time complexity - O(2^N)
int main() {
    vector<int> arr = {3, 1, 2};
    vector<int> ds;
    printSubsequences(0, arr, ds);
    return 0;
}
