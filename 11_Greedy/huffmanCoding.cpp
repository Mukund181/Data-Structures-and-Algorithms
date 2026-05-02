/* Huffman Coding Approach -
  Build a Min-Heap of nodes containing characters and frequencies.
  Extract two min nodes, create a new internal node with their sum, push back.
  Traverse tree to get codes. Left = 0, Right = 1.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

struct cmp {
    bool operator()(Node* l, Node* r) { return l->data > r->data; }
};

void printCodes(Node* root, string str, vector<string>& ans) {
    if(!root) return;
    if(!root->left && !root->right) ans.push_back(str);
    printCodes(root->left, str + "0", ans);
    printCodes(root->right, str + "1", ans);
}

vector<string> huffmanCodes(string S, vector<int>& f, int N) {
    priority_queue<Node*, vector<Node*>, cmp> pq;
    for(int i=0; i<N; i++) pq.push(new Node(f[i]));
    
    while(pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* top = new Node(left->data + right->data);
        top->left = left;
        top->right = right;
        pq.push(top);
    }
    vector<string> ans;
    printCodes(pq.top(), "", ans);
    return ans;
}

// time complexity - O(N log N)
int main() {
    string S = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
    vector<string> codes = huffmanCodes(S, f, 6);
    cout << "Huffman Codes: ";
    for(string s : codes) cout << s << " ";
    return 0;
}
