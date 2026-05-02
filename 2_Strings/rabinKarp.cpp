/* Rabin-Karp Algorithm Approach -
  Compute a rolling hash for the pattern and for windows in the text.
  If hashes match, perform a character-by-character check to avoid spurious hits.
*/
#include<iostream>
#include<string>
using namespace std;

void searchRabinKarp(string pat, string txt) {
    int d = 256;
    int q = 101; // A prime number
    int M = pat.length();
    int N = txt.length();
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
    
    for (i = 0; i < M - 1; i++) h = (h * d) % q;
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
    
    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) break;
            }
            if (j == M) cout << "Pattern found at index " << i << endl;
        }
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0) t = (t + q);
        }
    }
}

// time complexity - O(N+M) avg, O(N*M) worst
int main() {
    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEK";
    searchRabinKarp(pat, txt);
    return 0;
}
