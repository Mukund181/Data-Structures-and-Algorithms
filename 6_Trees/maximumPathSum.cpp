/* Maximum Path Sum Approach -
  Similar to diameter. Compute max path sum of left and right subtrees (ignore negative sums).
  Update global max path sum with (root->val + left sum + right sum).
  Return root->val + max(left, right) to parent.
*/
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxPathDown(TreeNode* node, int& maxi) {
    if (node == NULL) return 0;
    int left = max(0, maxPathDown(node->left, maxi));
    int right = max(0, maxPathDown(node->right, maxi));
    maxi = max(maxi, left + right + node->val);
    return max(left, right) + node->val;
}

int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    maxPathDown(root, maxi);
    return maxi;
}

// time complexity - O(N)
int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    cout << "Max Path Sum: " << maxPathSum(root) << endl;
    return 0;
}
