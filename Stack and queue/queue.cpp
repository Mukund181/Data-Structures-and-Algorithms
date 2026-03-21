#include<iostream>
#include<queue>
using namespace std;

class que {
    public :
    int front;
    int rear;
    int queue[10];
    int size=10;
    que(){
        front = rear =-1;
    }
    void enqueue(int d){
        if((rear+1)%size==front){ //overflow
            return;
        }
         // First element
        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        queue[rear] = d;
    }
    void dequeue(){
       // Underflow
        if (front == -1) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << "Deleted element: " << queue[front] << endl;

        // Last element removed
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }
};

int main(){
    //stl
    queue<int> q;
    q.push(19);
    q.push(12);
    q.push(34);
    cout<<"Front points to : "<<q.front()<<endl;
    cout<<"Back points to : "<<q.back()<<endl;
    q.pop();
    cout<<"New front element : "<<q.front()<<endl;

    // without stl
    que q1;
    q1.enqueue(18);
    q1.enqueue(11);
    q1.enqueue(23);
    q1.dequeue();
    q1.dequeue();
}