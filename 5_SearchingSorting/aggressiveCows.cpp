/* Aggressive Cows Approach -
  Binary search on the answer (distance).
  Sort stalls. Range of distance is 1 to (max_stall - min_stall).
  Check if a distance 'mid' is possible to place C cows.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canPlace(vector<int>& stalls, int n, int cows, int dist) {
    int count = 1;
    int lastPlaced = stalls[0];
    for(int i = 1; i < n; i++) {
        if(stalls[i] - lastPlaced >= dist) {
            count++;
            lastPlaced = stalls[i];
        }
        if(count >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1, high = stalls[n-1] - stalls[0];
    int res = 0;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(canPlace(stalls, n, cows, mid)) {
            res = mid;
            low = mid + 1; // Try to maximize distance
        } else {
            high = mid - 1;
        }
    }
    return res;
}

// time complexity - O(N log(MaxDist))
int main() {
    vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;
    cout << "Max min-distance: " << aggressiveCows(stalls, cows) << endl;
    return 0;
}
