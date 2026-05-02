/* String Compression Approach -
  Iterate through the string, counting consecutive identical characters.
  Write the character and its count (if > 1) back into the string array.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int compress(vector<char>& chars) {
    int i = 0, res = 0;
    while (i < chars.size()) {
        int groupLength = 1;
        while (i + groupLength < chars.size() && chars[i + groupLength] == chars[i]) {
            groupLength++;
        }
        chars[res++] = chars[i];
        if (groupLength > 1) {
            for (char c : to_string(groupLength)) {
                chars[res++] = c;
            }
        }
        i += groupLength;
    }
    return res;
}

// time complexity - O(N)
int main() {
    vector<char> chars = {'a','a','b','b','c','c','c'};
    int newLen = compress(chars);
    for(int i = 0; i < newLen; i++) cout << chars[i];
    cout << endl;
    return 0;
}
