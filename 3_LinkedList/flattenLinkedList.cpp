/* Flatten Linked List Approach -
  Merge two sorted linked lists repeatedly.
  Recursively flatten the rest of the list and merge it with the current list using bottom pointers.
*/
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* bottom;
    Node(int val) : data(val), next(nullptr), bottom(nullptr) {}
};

Node* mergeTwoLists(Node* a, Node* b) {
    Node* temp = new Node(0);
    Node* res = temp;
    
    while(a && b) {
        if(a->data < b->data) {
            temp->bottom = a;
            a = a->bottom;
        } else {
            temp->bottom = b;
            b = b->bottom;
        }
        temp = temp->bottom;
    }
    temp->bottom = a ? a : b;
    return res->bottom;
}

Node* flatten(Node* root) {
    if(!root || !root->next) return root;
    root->next = flatten(root->next);
    root = mergeTwoLists(root, root->next);
    return root;
}

// time complexity - O(N * M)
int main() {
    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->next = new Node(10);
    head->next->bottom = new Node(20);
    
    Node* res = flatten(head);
    while(res) { cout << res->data << " "; res = res->bottom; }
    return 0;
}
