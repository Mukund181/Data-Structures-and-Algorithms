/* Longest Common Subsequence Approach -
  DP state: dp[i][j] = LCS of string1 up to length i and string2 up to length j.
  If chars match: 1 + dp[i-1][j-1].
  Else: max(dp[i-1][j], dp[i][j-1]).
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

// time complexity - O(M * N)
int main() {
    cout << "LCS of 'abcde' and 'ace': " << longestCommonSubsequence("abcde", "ace") << endl;
    return 0;
}
