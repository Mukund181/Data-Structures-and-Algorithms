/* Reverse in K-Groups Approach -
  Count nodes. If >= k, reverse k nodes.
  Recursively call for the next group and attach it to the current group.
*/
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseKGroup(Node* head, int k) {
    Node* curr = head;
    int count = 0;
    while(curr != nullptr && count != k) {
        curr = curr->next;
        count++;
    }
    
    if(count == k) {
        curr = reverseKGroup(curr, k);
        while(count > 0) {
            Node* temp = head->next;
            head->next = curr;
            curr = head;
            head = temp;
            count--;
        }
        head = curr;
    }
    return head;
}

// time complexity - O(N)
int main() {
    Node* head = new Node(1); head->next = new Node(2); head->next->next = new Node(3);
    head->next->next->next = new Node(4); head->next->next->next->next = new Node(5);
    
    Node* res = reverseKGroup(head, 2);
    while(res) { cout << res->data << " "; res = res->next; }
    return 0;
}
