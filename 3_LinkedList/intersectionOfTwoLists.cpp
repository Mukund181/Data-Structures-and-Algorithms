/* Intersection of Two Linked Lists Approach -
  Two pointers, p1 and p2 starting at headA and headB.
  When a pointer reaches the end, reset it to the head of the other list.
  They will eventually meet at the intersection node or at NULL.
*/
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* getIntersectionNode(Node* headA, Node* headB) {
    if(!headA || !headB) return nullptr;
    Node* pA = headA;
    Node* pB = headB;
    
    while(pA != pB) {
        pA = pA == nullptr ? headB : pA->next;
        pB = pB == nullptr ? headA : pB->next;
    }
    return pA;
}

// time complexity - O(N + M)
int main() {
    Node* intersection = new Node(8);
    intersection->next = new Node(10);
    
    Node* headA = new Node(4); headA->next = new Node(1); headA->next->next = intersection;
    Node* headB = new Node(5); headB->next = new Node(6); headB->next->next = new Node(1); headB->next->next->next = intersection;
    
    Node* res = getIntersectionNode(headA, headB);
    if(res) cout << "Intersection at: " << res->data << endl;
    return 0;
}
