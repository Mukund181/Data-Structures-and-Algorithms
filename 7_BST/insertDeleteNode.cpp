/* Insert/Delete Node in BST Approach -
  Insert: Traverse tree, find null spot maintaining BST property.
  Delete: 3 cases (Leaf, 1 Child, 2 Children). For 2 children, replace with inorder successor/predecessor and delete it.
*/
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root) return new TreeNode(val);
    if(val < root->val) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return root;
    if(key < root->val) root->left = deleteNode(root->left, key);
    else if(key > root->val) root->right = deleteNode(root->right, key);
    else {
        if(!root->left) return root->right;
        else if(!root->right) return root->left;
        
        TreeNode* minNode = root->right;
        while(minNode->left) minNode = minNode->left;
        root->val = minNode->val;
        root->right = deleteNode(root->right, root->val);
    }
    return root;
}

void inorder(TreeNode* root) {
    if(!root) return;
    inorder(root->left); cout << root->val << " "; inorder(root->right);
}

// time complexity - O(H)
int main() {
    TreeNode* root = new TreeNode(5);
    root = insertIntoBST(root, 3);
    root = insertIntoBST(root, 6);
    root = insertIntoBST(root, 2);
    root = insertIntoBST(root, 4);
    root = insertIntoBST(root, 7);
    cout << "Inorder before: "; inorder(root); cout << endl;
    
    root = deleteNode(root, 3);
    cout << "Inorder after deleting 3: "; inorder(root); cout << endl;
    return 0;
}
