/* Rat in a Maze Approach -
  Start from (0,0). Move D, L, R, U.
  Check if next move is valid (inside bounds, is '1', not visited).
  If valid, recurse. Backtrack by unmarking visited.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solveMaze(int i, int j, vector<vector<int>>& m, int n, vector<string>& ans, string move, vector<vector<int>>& vis) {
    if(i == n - 1 && j == n - 1) {
        ans.push_back(move);
        return;
    }
    
    int di[] = {1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};
    string dir = "DLRU";
    
    for(int idx = 0; idx < 4; idx++) {
        int nextI = i + di[idx];
        int nextJ = j + dj[idx];
        
        if(nextI >= 0 && nextJ >= 0 && nextI < n && nextJ < n && !vis[nextI][nextJ] && m[nextI][nextJ] == 1) {
            vis[i][j] = 1;
            solveMaze(nextI, nextJ, m, n, ans, move + dir[idx], vis);
            vis[i][j] = 0; // backtrack
        }
    }
}

// time complexity - O(4^(N*N))
int main() {
    int n = 4;
    vector<vector<int>> m = {{1,0,0,0}, {1,1,0,1}, {1,1,0,0}, {0,1,1,1}};
    vector<vector<int>> vis(n, vector<int>(n, 0));
    vector<string> ans;
    if(m[0][0] == 1) solveMaze(0, 0, m, n, ans, "", vis);
    
    for(string s : ans) cout << s << " ";
    return 0;
}
