/* Copy List with Random Pointer Approach -
  Step 1: Interweave copied nodes with original nodes (A -> A' -> B -> B').
  Step 2: Assign random pointers for the copied nodes.
  Step 3: Separate the interweaved list into original and copied lists.
*/
#include<iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    
    // Step 1
    Node* curr = head;
    while (curr) {
        Node* newNode = new Node(curr->val);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }
    
    // Step 2
    curr = head;
    while (curr) {
        if (curr->random) curr->next->random = curr->random->next;
        curr = curr->next->next;
    }
    
    // Step 3
    curr = head;
    Node* pseudoHead = new Node(0);
    Node* copyCurr = pseudoHead;
    
    while (curr) {
        Node* nextOrig = curr->next->next;
        copyCurr->next = curr->next;
        curr->next = nextOrig;
        
        copyCurr = copyCurr->next;
        curr = nextOrig;
    }
    
    Node* result = pseudoHead->next;
    delete pseudoHead;
    return result;
}

// time complexity - O(N)
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->random = head->next;
    head->next->random = head;
    
    Node* copy = copyRandomList(head);
    cout << "Copied List Head: " << copy->val << endl;
    return 0;
}
