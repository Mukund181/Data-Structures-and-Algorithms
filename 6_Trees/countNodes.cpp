/* Count Nodes Approach -
  Total nodes = 1 + countNodes(left) + countNodes(right).
  If it's a complete binary tree, can be optimized to O(log^2 N).
*/
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countNodes(TreeNode* root) {
    if(!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// time complexity - O(N)
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    
    cout << "Total Nodes: " << countNodes(root) << endl;
    return 0;
}
