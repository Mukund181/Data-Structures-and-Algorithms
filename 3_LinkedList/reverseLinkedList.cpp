/* Reverse Linked List Approach -
  Use three pointers: prev, curr, and next.
  Iterate through the list, continually pointing the current node to the previous node.
*/
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    
    while(curr != nullptr) {
        next = curr->next; // store next
        curr->next = prev; // reverse link
        prev = curr;       // move prev forward
        curr = next;       // move curr forward
    }
    return prev; // new head
}

// time complexity - O(N)
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    
    Node* rev = reverseList(head);
    while(rev) { cout << rev->data << " "; rev = rev->next; }
    return 0;
}
