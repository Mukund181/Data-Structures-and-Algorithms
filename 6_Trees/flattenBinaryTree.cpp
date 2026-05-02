/* Flatten Binary Tree to Linked List Approach -
  Right, Left, Root traversal (Reverse Postorder).
  Keep track of 'prev' node. Current node's right points to prev, left points to NULL.
  Update prev to current node.
*/
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode* root) {
    static TreeNode* prev = NULL;
    if(!root) return;
    
    flatten(root->right);
    flatten(root->left);
    
    root->right = prev;
    root->left = NULL;
    prev = root;
}

// time complexity - O(N)
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    flatten(root);
    cout << "Flattened: ";
    TreeNode* curr = root;
    while(curr) { cout << curr->val << " "; curr = curr->right; }
    return 0;
}
