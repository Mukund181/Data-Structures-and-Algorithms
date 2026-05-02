/* Search in BST Approach -
  If root matches, return root.
  If target < root->val, search left. Else search right.
*/
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* searchBST(TreeNode* root, int val) {
    if(!root || root->val == val) return root;
    if(val < root->val) return searchBST(root->left, val);
    return searchBST(root->right, val);
}

// time complexity - O(H) where H is height of tree
int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    
    TreeNode* res = searchBST(root, 2);
    if(res) cout << "Found: " << res->val << endl;
    return 0;
}
