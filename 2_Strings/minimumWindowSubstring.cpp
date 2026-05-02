/* Minimum Window Substring Approach -
  Use a sliding window and a hash map to keep track of required character frequencies.
  Expand window by moving right pointer. Once all characters are matched, try shrinking from the left.
*/
#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;

string minWindow(string s, string t) {
    vector<int> map(128, 0);
    for (char c : t) map[c]++;
    int counter = t.length(), left = 0, right = 0, d = INT_MAX, head = 0;
    
    while (right < s.length()) {
        if (map[s[right++]]-- > 0) counter--;
        while (counter == 0) { // valid window
            if (right - left < d) d = right - (head = left);
            if (map[s[left++]]++ == 0) counter++; // make it invalid
        }
    }
    return d == INT_MAX ? "" : s.substr(head, d);
}

// time complexity - O(N)
int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    cout << "Min Window: " << minWindow(s, t) << endl;
    return 0;
}
