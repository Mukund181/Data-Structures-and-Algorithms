/* Traverse Linked List Approach -
  Iterate through the linked list starting from the head.
  Print the data of each node until the current node becomes NULL.
*/
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void traverse(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// time complexity - O(N)
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    
    traverse(head);
    return 0;
}
