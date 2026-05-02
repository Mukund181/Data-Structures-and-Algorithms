/* Set Matrix Zeroes Approach -
  If an element is 0, set its entire row and column to 0.
  Use first row and first col as markers to record which rows/cols need to be zeroed.
  A variable 'col0' tracks if the first column needs to be zeroed.
*/
#include<iostream>
#include<vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    bool col0 = false;

    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = true;
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
        if (col0) matrix[i][0] = 0;
    }
}

// time complexity - O(N * M)
int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(matrix);
    for(auto row : matrix) {
        for(int val : row) cout << val << " ";
        cout << endl;
    }
    return 0;
}
