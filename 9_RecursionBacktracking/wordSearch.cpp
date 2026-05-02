/* Word Search Approach -
  Find given word in 2D grid of chars.
  Start DFS from any cell matching first char.
  If next char matches, continue DFS in 4 directions. Backtrack by restoring char.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool dfs(int i, int j, int idx, vector<vector<char>>& board, string& word) {
    if(idx == word.length()) return true;
    
    if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx]) {
        return false;
    }
    
    char temp = board[i][j];
    board[i][j] = '*'; // visited
    
    bool found = dfs(i + 1, j, idx + 1, board, word) ||
                 dfs(i - 1, j, idx + 1, board, word) ||
                 dfs(i, j + 1, idx + 1, board, word) ||
                 dfs(i, j - 1, idx + 1, board, word);
                 
    board[i][j] = temp; // backtrack
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(board[i][j] == word[0] && dfs(i, j, 0, board, word)) {
                return true;
            }
        }
    }
    return false;
}

// time complexity - O(N * M * 4^L)
int main() {
    vector<vector<char>> board = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    cout << "Contains 'ABCCED': " << exist(board, "ABCCED") << endl;
    return 0;
}
