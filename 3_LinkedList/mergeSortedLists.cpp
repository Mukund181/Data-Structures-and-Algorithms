/* Merge Two Sorted Lists Approach -
  Use a dummy node to build the new list.
  Compare heads of both lists, append the smaller one to dummy, and advance its pointer.
  Append remaining nodes of the list that is not empty.
*/
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* mergeTwoLists(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* curr = dummy;
    
    while(l1 && l2) {
        if(l1->data <= l2->data) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    curr->next = l1 ? l1 : l2;
    
    Node* res = dummy->next;
    delete dummy;
    return res;
}

// time complexity - O(N + M)
int main() {
    Node* l1 = new Node(1); l1->next = new Node(3); l1->next->next = new Node(5);
    Node* l2 = new Node(2); l2->next = new Node(4); l2->next->next = new Node(6);
    
    Node* merged = mergeTwoLists(l1, l2);
    while(merged) { cout << merged->data << " "; merged = merged->next; }
    return 0;
}
