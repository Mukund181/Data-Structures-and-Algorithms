/* Merge Overlapping Intervals Approach -
  1. Sort intervals by their start time.
  2. Iterate and check if the current interval overlaps with the last added interval in the result.
  3. If it overlaps, merge them by updating the end time of the last added interval.
  4. Otherwise, add it to the result.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;

    for (auto interval : intervals) {
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval); // No overlap
        } else {
            merged.back()[1] = max(merged.back()[1], interval[1]); // Overlap, merge
        }
    }
    return merged;
}

// time complexity - O(N log N)
int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans = mergeIntervals(intervals);
    for(auto i : ans) cout << "[" << i[0] << "," << i[1] << "] ";
    return 0;
}
