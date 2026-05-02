/* Insert/Delete Node Approach -
  Insert: create a new node and adjust pointers to insert at head, tail, or specific position.
  Delete: adjust pointers to bypass the node to be deleted, then free its memory.
*/
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* insertAtHead(Node* head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    return newNode;
}

Node* deleteNode(Node* head, int val) {
    if(!head) return nullptr;
    if(head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    Node* curr = head;
    while(curr->next && curr->next->data != val) {
        curr = curr->next;
    }
    if(curr->next) {
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
    return head;
}

void print(Node* head) {
    while(head) { cout << head->data << " -> "; head = head->next; }
    cout << "NULL\n";
}

// time complexity - O(N) for deletion, O(1) for insert at head
int main() {
    Node* head = nullptr;
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 30);
    print(head);
    
    head = deleteNode(head, 20);
    print(head);
    return 0;
}
