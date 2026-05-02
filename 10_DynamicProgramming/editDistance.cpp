/* Edit Distance Approach -
  Find min operations (Insert, Delete, Replace) to convert word1 to word2.
  DP state: dp[i][j] = edit dist of word1[0..i] and word2[0..j].
  Transition: If match, dp[i-1][j-1]. Else 1 + min(insert, delete, replace).
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for(int i = 0; i <= m; i++) dp[i][0] = i;
    for(int j = 0; j <= n; j++) dp[0][j] = j;
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
    }
    return dp[m][n];
}

// time complexity - O(M * N)
int main() {
    cout << "Edit dist 'horse' to 'ros': " << minDistance("horse", "ros") << endl;
    return 0;
}
