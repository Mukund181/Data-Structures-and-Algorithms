/* Lowest Common Ancestor Approach -
  Recursively search for p and q.
  If root matches p or q, return root.
  If p and q are in left and right subtrees respectively, root is the LCA.
  Otherwise, return the non-null subtree result.
*/
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q) return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if(left != NULL && right != NULL) return root;
    
    return left != NULL ? left : right;
}

// time complexity - O(N)
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    
    TreeNode* lca = lowestCommonAncestor(root, root->left, root->right);
    cout << "LCA of 5 and 1: " << lca->val << endl;
    return 0;
}
