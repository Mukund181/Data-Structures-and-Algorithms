/* Remove Nth Node from End Approach -
  Use a dummy node pointing to head.
  Use two pointers, fast and slow. Advance fast by N steps.
  Then advance both until fast reaches the last node.
  Slow will be just before the node to remove.
*/
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* removeNthFromEnd(Node* head, int n) {
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* fast = dummy;
    Node* slow = dummy;
    
    for(int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    
    while(fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    
    Node* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    
    Node* res = dummy->next;
    delete dummy;
    return res;
}

// time complexity - O(N)
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    head = removeNthFromEnd(head, 2); // remove 4
    
    while(head) { cout << head->data << " "; head = head->next; }
    return 0;
}
