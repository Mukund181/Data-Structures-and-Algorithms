/* Recover BST Approach -
  Two nodes are swapped in a BST.
  Inorder traversal should be sorted. Keep track of 'prev' node.
  If prev->val > curr->val, a swap occurred. Store first and second violations.
  Swap values of first and second to recover.
*/
#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* firstElem = NULL;
TreeNode* secondElem = NULL;
TreeNode* prevElem = new TreeNode(-1e9);

void inorder(TreeNode* root) {
    if(!root) return;
    inorder(root->left);
    
    if(firstElem == NULL && prevElem->val > root->val) {
        firstElem = prevElem;
    }
    if(firstElem != NULL && prevElem->val > root->val) {
        secondElem = root;
    }
    prevElem = root;
    
    inorder(root->right);
}

void recoverTree(TreeNode* root) {
    inorder(root);
    swap(firstElem->val, secondElem->val);
}

// time complexity - O(N)
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2); // 2 and 3 are swapped
    
    recoverTree(root);
    cout << "Recovered Root: " << root->val << endl; // Should be 2
    return 0;
}
