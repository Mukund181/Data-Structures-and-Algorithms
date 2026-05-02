/* Check Balanced Tree Approach -
  A tree is balanced if diff between heights of left and right subtrees <= 1 for ALL nodes.
  Modify height function to return -1 if unbalanced.
*/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int checkHeight(TreeNode* root) {
    if(!root) return 0;
    int lh = checkHeight(root->left);
    if(lh == -1) return -1;
    int rh = checkHeight(root->right);
    if(rh == -1) return -1;
    
    if(abs(lh - rh) > 1) return -1;
    return 1 + max(lh, rh);
}

bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}

// time complexity - O(N)
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    
    cout << "Is Balanced: " << isBalanced(root) << endl;
    return 0;
}
