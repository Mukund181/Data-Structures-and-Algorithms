/* Number of Islands Approach -
  Traverse the 2D grid. When '1' (land) is found, increment island count.
  Run BFS/DFS to mark all connected '1's as '0' (visited) so they aren't counted again.
*/
#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j) {
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return;
    grid[i][j] = '0'; // mark as visited
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == '1') {
                count++;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}

// time complexity - O(N * M)
int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << "Number of Islands: " << numIslands(grid) << endl;
    return 0;
}
