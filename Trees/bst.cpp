#include<iostream>
#include<queue>
using namespace std;

class Node {
    public :
    Node *lchild;
    Node *rchild;
    int data;
    Node(int d){
        data =d;
        lchild=rchild=nullptr;
    }
};

Node* insertNode(Node *root,int key){
    if(root==nullptr){
        return new Node(key);
    }
    if(key>root->data){
        root->rchild = insertNode(root->rchild,key);
    }
    else if(key<root->data){
        root->lchild = insertNode(root->lchild,key);
    }
    if(key == root->data){ return root; }

    return root;
}
// dfs algorithms for tree -> uses stack/recursion
void inorder(Node *root){
    // left->root->right
    if(root==nullptr){ return;}
    inorder(root->lchild);
    cout<<root->data<<" ";
    inorder(root->rchild);
}
void preorder(Node *root){
   // root->left->right
   if(root==nullptr){ return; }
   cout<<root->data<<" ";
   preorder(root->lchild);
   preorder(root->rchild);
}
void postorder(Node *root){
   // left->right->root
   if(root==nullptr){ return; }
   postorder(root->lchild);
   postorder(root->rchild);
   cout<<root->data<<" ";
}   
// bfs for tree -> uses queue
void levelordertraversal(Node *root){
   
}
int main(){
    Node *root=nullptr;
    root = insertNode(root,60);
    root = insertNode(root,40);
    root = insertNode(root,100);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
}