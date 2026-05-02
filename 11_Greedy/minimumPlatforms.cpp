/* Minimum Platforms Approach -
  Sort arrival and departure times separately.
  Use two pointers to traverse both arrays.
  If arrival <= departure, platform needed, i++.
  Else platform freed, j++. Maximize platforms needed.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findPlatform(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    
    int plat_needed = 1, result = 1;
    int i = 1, j = 0, n = arr.size();
    
    while(i < n && j < n) {
        if(arr[i] <= dep[j]) {
            plat_needed++;
            i++;
        } else {
            plat_needed--;
            j++;
        }
        result = max(result, plat_needed);
    }
    return result;
}

// time complexity - O(N log N)
int main() {
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << "Min Platforms: " << findPlatform(arr, dep) << endl;
    return 0;
}
