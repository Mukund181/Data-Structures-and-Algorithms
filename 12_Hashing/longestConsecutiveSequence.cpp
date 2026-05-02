/* Longest Consecutive Sequence Approach -
  Insert all elements into a Hash Set.
  Iterate. If (element - 1) is not in set, it's the start of a sequence.
  Count consecutive elements from this start. Maximize count.
*/
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> hashSet(nums.begin(), nums.end());
    int longestSeq = 0;
    
    for(int num : nums) {
        if(!hashSet.count(num - 1)) {
            int currentNum = num;
            int currentStreak = 1;
            while(hashSet.count(currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }
            longestSeq = max(longestSeq, currentStreak);
        }
    }
    return longestSeq;
}

// time complexity - O(N)
int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest sequence: " << longestConsecutive(nums) << endl;
    return 0;
}
