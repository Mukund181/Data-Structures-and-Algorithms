#include<iostream>
using namespace std;

class Node{
   public :
   Node *next;
   int data;
   Node(int d){
    data=d;
    next=nullptr;
   }
};
void printLL(Node *head){
    Node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node *reverseLL(Node *head){
    Node *prev=nullptr;  // for prev node , initally null as head's next becomes null in reverse
    Node *curr = head;  //current node
    while(curr!=nullptr){
        Node *temp = curr->next;   // storing next node in temp variable
        curr->next=prev;  // prev becomes next of curr 
        prev = curr;  // current becomes previous for next(temp) i.e next current
        curr = temp; // current's next stored as temp becomes next current node
    }
    return prev;   // last prev becomes new head of LL
}
int main(){
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next= new Node(3);
    head->next->next->next= new Node(4);
    printLL(head);
    head = reverseLL(head);
    printLL(head);
}