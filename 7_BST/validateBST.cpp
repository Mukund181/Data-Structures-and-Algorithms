/* Validate BST Approach -
  Each node must fall within a strict range (minVal, maxVal).
  Left child's max boundary is root's value. Right child's min boundary is root's value.
*/
#include<iostream>
#include<climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBSTUtil(TreeNode* root, long minVal, long maxVal) {
    if(!root) return true;
    if(root->val <= minVal || root->val >= maxVal) return false;
    return isValidBSTUtil(root->left, minVal, root->val) &&
           isValidBSTUtil(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isValidBSTUtil(root, LONG_MIN, LONG_MAX);
}

// time complexity - O(N)
int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    
    cout << "Is Valid BST: " << isValidBST(root) << endl;
    return 0;
}
