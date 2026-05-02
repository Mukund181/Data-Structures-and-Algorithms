/* Subset Sum Approach -
  Find all subset sums of an array.
  For each element, either include it in sum or exclude it. Recurse.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void subsetSums(int idx, int sum, vector<int>& arr, vector<int>& ans) {
    if(idx == arr.size()) {
        ans.push_back(sum);
        return;
    }
    // Include the element
    subsetSums(idx + 1, sum + arr[idx], arr, ans);
    
    // Exclude the element
    subsetSums(idx + 1, sum, arr, ans);
}

// time complexity - O(2^N)
int main() {
    vector<int> arr = {5, 2, 1};
    vector<int> ans;
    subsetSums(0, 0, arr, ans);
    sort(ans.begin(), ans.end());
    cout << "Subset sums: ";
    for(int s : ans) cout << s << " ";
    return 0;
}
