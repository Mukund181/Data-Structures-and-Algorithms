/* Implement strStr() Approach -
  Find the first occurrence of needle in haystack.
  Iterate through haystack and check substring matching.
*/
#include<iostream>
#include<string>
using namespace std;

int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    int hLen = haystack.length(), nLen = needle.length();
    
    for (int i = 0; i <= hLen - nLen; i++) {
        int j = 0;
        while (j < nLen && haystack[i + j] == needle[j]) {
            j++;
        }
        if (j == nLen) return i;
    }
    return -1;
}

// time complexity - O(N * M)
int main() {
    string haystack = "sadbutsad", needle = "sad";
    cout << "Index: " << strStr(haystack, needle) << endl;
    return 0;
}
