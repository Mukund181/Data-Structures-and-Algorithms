/* Serialize and Deserialize Tree Approach -
  Serialize: Use Preorder traversal. Append 'null' for empty nodes. Separated by comma.
  Deserialize: Use stringstream. Recursively build tree following Preorder.
*/
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root) return "null,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    TreeNode* deserializeHelper(stringstream& ss) {
        string str;
        getline(ss, str, ',');
        if(str == "null") return NULL;
        TreeNode* root = new TreeNode(stoi(str));
        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);
        return root;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
};

// time complexity - O(N)
int main() {
    Codec codec;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    string serialized = codec.serialize(root);
    cout << "Serialized: " << serialized << endl;
    TreeNode* deserialized = codec.deserialize(serialized);
    cout << "Deserialized Root: " << deserialized->val << endl;
    return 0;
}
