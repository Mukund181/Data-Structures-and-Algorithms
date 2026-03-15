#include<iostream>
using namespace std;

class Node{
    public :
    Node *prev;
    Node *next;
    int data;
    Node(int d){
        data =d;
        next=prev=nullptr;
    }
};
  Node *insert_start(Node *head,int key){
         Node *nn = new Node(key);
                if(head==nullptr){
                    head=nn;
                }
                else {
                    nn->next=head;
                    head->prev=nn;
                    head=nn;
                }      
        return head;
            
    }
Node *insertpos(Node *head,int key,int pos){
    Node *nn = new Node(key);
    if(head==nullptr){
        head=nn;
    }
    else {
        Node *temp=head;
        while(temp->data!=pos){
            temp = temp->next;
        }
        temp->next->prev=nn;
        nn->next=temp->next;
        temp->next=nn;
        nn->prev=temp;
    }

    return head;
}
Node *insert_end(Node *head,int key){
   Node *nn = new Node(key);
   if(head==nullptr){
    head = nn;
   }
   else {
    Node *temp=head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next=nn;
    nn->prev=temp;
   }
   return head;
}
Node *deleteNode(Node *head,int key){
    if(head==nullptr){
        return nullptr;
    }
    else {
        if(head->data==key){
            Node *temp=head;
            head = head->next;
            head->prev=nullptr;
            delete temp;
        }
        else {
            Node *temp=head;
            while(temp!=nullptr && temp->next->data!=key){
                temp = temp->next;
            }
             if(temp->next->next==nullptr){ // end condition
                    Node *todel=temp->next;
                    temp->next=nullptr;
                    delete todel;
                }
             else { // middle condition
                    Node *to_del = temp->next;
                    temp->next->next->prev=temp;
                    temp->next = temp->next->next;
                    delete to_del;
            }
        }
    }
    return head;
}
void print_LL(Node *head){
    Node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}          
int main(){
   Node *head= new Node(11);
   head = insert_start(head,22);
   head = insert_start(head,26);
   head = insertpos(head,23,22);
   head = insert_end(head,45);
   print_LL(head);
   head = deleteNode(head,26);
   print_LL(head);
   head = deleteNode(head,45);
   print_LL(head);
   head = deleteNode(head,23);
   print_LL(head);
}