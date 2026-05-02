/* KMP Algorithm Approach -
  Preprocess the pattern to construct an LPS (Longest Proper Prefix which is also Suffix) array.
  Use LPS to skip characters while matching to avoid redundant comparisons.
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void computeLPSArray(string pat, int M, vector<int>& lps) {
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string pat, string txt) {
    int M = pat.length(), N = txt.length();
    vector<int> lps(M);
    computeLPSArray(pat, M, lps);
    
    int i = 0, j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++; i++;
        }
        if (j == M) {
            cout << "Found pattern at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
}

// time complexity - O(N+M)
int main() {
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}
