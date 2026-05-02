/* DP on Trees Approach -
  Used for problems like Diameter, Max Path Sum.
  Each node returns a value to its parent, and also updates a global answer based on both subtrees.
*/
#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxPathSumHelper(TreeNode* root, int& ans) {
    if(!root) return 0;
    
    int leftSum = max(0, maxPathSumHelper(root->left, ans));
    int rightSum = max(0, maxPathSumHelper(root->right, ans));
    
    // Update global max using both subtrees
    ans = max(ans, leftSum + rightSum + root->val);
    
    // Return max path going down one branch
    return root->val + max(leftSum, rightSum);
}

// time complexity - O(N)
int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    int ans = -1e9;
    maxPathSumHelper(root, ans);
    cout << "Max path sum (DP on Tree): " << ans << endl;
    return 0;
}
