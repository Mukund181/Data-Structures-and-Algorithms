/* Longest Common Prefix Approach -
  Take the first string as the initial prefix.
  Compare it with each string, shortening the prefix until it matches the beginning.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix.empty()) return "";
        }
    }
    return prefix;
}

// time complexity - O(N * M)
int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Prefix: " << longestCommonPrefix(strs) << endl;
    return 0;
}
