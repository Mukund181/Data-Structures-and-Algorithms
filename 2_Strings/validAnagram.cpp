/* Valid Anagram Approach -
  Count frequencies of characters in both strings.
  If lengths differ, not an anagram.
  Increment counts for string 1, decrement for string 2. All counts must be 0.
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    vector<int> count(26, 0);
    
    for (int i = 0; i < s.length(); i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    
    for (int c : count) {
        if (c != 0) return false;
    }
    return true;
}

// time complexity - O(N)
int main() {
    cout << "anagram vs nagaram: " << isAnagram("anagram", "nagaram") << endl;
    return 0;
}
