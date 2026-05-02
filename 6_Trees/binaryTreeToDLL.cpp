/* Binary Tree to DLL Approach -
  Use Inorder traversal.
  Keep track of a 'prev' pointer. For each node, link it with 'prev'.
  If 'prev' is NULL, this node is the 'head' of the DLL.
*/
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void bToDLL(TreeNode* root, TreeNode*& head, TreeNode*& prev) {
    if(root == NULL) return;
    bToDLL(root->left, head, prev);
    
    if(prev == NULL) head = root;
    else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    
    bToDLL(root->right, head, prev);
}

// time complexity - O(N)
int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(12);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(25);
    root->left->right = new TreeNode(30);
    root->right->left = new TreeNode(36);
    
    TreeNode* head = NULL;
    TreeNode* prev = NULL;
    bToDLL(root, head, prev);
    
    cout << "DLL Forward: ";
    TreeNode* curr = head;
    while(curr) { cout << curr->val << " "; curr = curr->right; }
    cout << endl;
    return 0;
}
