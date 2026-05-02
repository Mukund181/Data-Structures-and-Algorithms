/* Kth Smallest Element in BST Approach -
  Inorder traversal of BST gives elements in sorted order.
  Do inorder traversal and keep track of count. When count == k, return node.
*/
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode* root, int& k, int& ans) {
    if(!root) return;
    inorder(root->left, k, ans);
    k--;
    if(k == 0) {
        ans = root->val;
        return;
    }
    inorder(root->right, k, ans);
}

int kthSmallest(TreeNode* root, int k) {
    int ans = -1;
    inorder(root, k, ans);
    return ans;
}

// time complexity - O(N) worst case, O(H + k) average
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    
    cout << "1st Smallest: " << kthSmallest(root, 1) << endl;
    return 0;
}
