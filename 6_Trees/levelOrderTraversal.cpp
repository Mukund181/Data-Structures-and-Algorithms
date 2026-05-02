/* Level Order Traversal Approach -
  Use a Queue to perform Breadth-First Search (BFS).
  Push root to queue. While queue is not empty, process all nodes at current level.
  Add their children to the queue for the next level.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        for(int i=0; i<size; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans.push_back(level);
    }
    return ans;
}

// time complexity - O(N)
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    vector<vector<int>> res = levelOrder(root);
    for(auto lvl : res) {
        for(int val : lvl) cout << val << " ";
        cout << "| ";
    }
    return 0;
}
