/* Subarrays with XOR = K Approach -
  Keep track of the prefix XOR.
  Use a hash map to store the frequency of prefix XOR values seen so far.
  For each element, calculate current prefix XOR, check if (xr ^ k) exists in map.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarraysWithXorK(vector<int> a, int b) {
    int xr = 0;
    unordered_map<int, int> mpp;
    mpp[0] = 1; // Base case
    int count = 0;

    for (int i = 0; i < a.size(); i++) {
        xr = xr ^ a[i];
        int x = xr ^ b;
        if (mpp.find(x) != mpp.end()) {
            count += mpp[x];
        }
        mpp[xr]++;
    }
    return count;
}

// time complexity - O(N)
int main() {
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    cout << "Count: " << subarraysWithXorK(a, k) << endl;
    return 0;
}
