/* Detect Cycle (Floyd's Cycle) Approach -
  Use slow and fast pointers.
  If there is a cycle, fast will eventually catch up and equal slow.
  If fast reaches NULL, there is no cycle.
*/
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

// time complexity - O(N)
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head->next; // creates a cycle
    
    cout << "Has cycle: " << detectCycle(head) << endl;
    return 0;
}
