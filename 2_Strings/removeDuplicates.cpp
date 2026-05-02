/* Remove Duplicates Approach -
  Use a boolean array (or hash map) to keep track of seen characters.
  Build a new string with only unseen characters.
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

string removeDuplicates(string s) {
    vector<bool> seen(256, false);
    string result = "";
    for(char ch : s) {
        if(!seen[ch]) {
            result += ch;
            seen[ch] = true;
        }
    }
    return result;
}

// time complexity - O(N)
int main() {
    string s = "programming";
    cout << "Original: " << s << endl;
    cout << "No duplicates: " << removeDuplicates(s) << endl;
    return 0;
}
