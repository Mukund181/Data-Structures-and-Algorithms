/* Find Middle of List Approach -
  Use slow and fast pointers.
  Slow moves 1 step, fast moves 2 steps.
  When fast reaches the end, slow is at the middle.
*/
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// time complexity - O(N)
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    Node* mid = findMiddle(head);
    if(mid) cout << "Middle is: " << mid->data << endl;
    return 0;
}
