#include<iostream>
using namespace std;

class node{
    public :
    node *next;
    int data;
    node(int d){
       data =d;
       next=nullptr;
    }
};

class LL{
    public :
    node *head;
    LL(){
        head=nullptr;
    }
    void insertStart(int key){
        if(head==nullptr){
            node *nn=new node(key);
            head=nn;
        }
        else {
            node *nn = new node(key);
            nn->next=head;
            head = nn;
        }
    }
    void insertEnd(int key){
        node *nn=new node(key);
        if(head==nullptr){
            head=nn;
        }
        else {
            node *temp=head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=nn;
        }
    }
    void insertBetween(int key,int x){
        node *nn=new node(key);
        if(head==nullptr){
            head=nn;
        }
        else {
            node *temp=head;
            while(temp!=nullptr && temp->data!=x){
                temp=temp->next;
            }
            nn->next = temp->next;
            temp->next=nn;
        }
    }
    void display(){
        node *temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
    void deleteElement(int key){
        if(head==nullptr){ return; }
        else {
            if(head->data==key){ // head condition
            node *temp=head;
            head = head->next;
            delete temp;
            }
            else {
                node*temp=head;
                while(temp!=nullptr && temp->next->data!=key){
                    temp=temp->next;
                }
                if(temp->next->next==nullptr){ // end condition
                    node *todel=temp->next;
                    delete todel;
                    temp->next=nullptr;
                }
                else { // middle condition
                    node *todel=temp->next;
                    temp->next=temp->next->next;
                    delete todel;
                }
            }
        }
    }
};
int main(){
    LL li;
    li.insertStart(2);
    li.insertStart(3);
    li.insertEnd(5);
    li.insertBetween(8,3);
    li.display();
    li.deleteElement(3);
    li.display();
    li.deleteElement(2);
    li.display();
}