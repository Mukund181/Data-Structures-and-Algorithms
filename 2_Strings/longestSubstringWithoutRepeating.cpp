/* Longest Substring Without Repeating Characters Approach -
  Use a sliding window with a hash map (or vector) to store the last seen index of characters.
  If a character is repeated, move the left pointer past its last seen index.
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> lastIndex(256, -1);
    int maxLen = 0, left = 0;
    
    for (int right = 0; right < s.length(); right++) {
        if (lastIndex[s[right]] != -1) {
            left = max(left, lastIndex[s[right]] + 1);
        }
        lastIndex[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

// time complexity - O(N)
int main() {
    string s = "abcabcbb";
    cout << "Max Length: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}
