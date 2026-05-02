/* N-Queens Approach -
  Place queens row by row.
  For each cell, check if safe (no queens in same column, upper-left diagonal, upper-right diagonal).
  If safe, place queen and recurse for next row. Backtrack afterwards.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSafe(int row, int col, vector<string>& board, int n) {
    int dupRow = row, dupCol = col;
    while(row >= 0 && col >= 0) { if(board[row][col] == 'Q') return false; row--; col--; }
    
    row = dupRow; col = dupCol;
    while(col >= 0) { if(board[row][col] == 'Q') return false; col--; }
    
    row = dupRow; col = dupCol;
    while(row < n && col >= 0) { if(board[row][col] == 'Q') return false; row++; col--; }
    
    return true;
}

void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
    if(col == n) {
        ans.push_back(board);
        return;
    }
    for(int row = 0; row < n; row++) {
        if(isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.'; // backtrack
        }
    }
}

// time complexity - O(N!)
int main() {
    int n = 4;
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    solve(0, board, ans, n);
    cout << "Solutions: " << ans.size() << endl;
    return 0;
}
