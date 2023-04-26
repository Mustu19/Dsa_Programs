#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Queue{
    
    class node{
        public :
            int data;
            node *next;
            node(int d = 0){
                data = d;
                next = nullptr;
            }
    };

    node *front;
    node *rear;

    public :
        Queue(){
            front = nullptr;
            rear = nullptr;
        }

        bool isEmpty(){
            return (front == nullptr);
        }

        void display(){
            node *temp = front;

            if(isEmpty()){
                cout << "Empty Queue." << endl;
            }
            while(temp!=nullptr){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        void enQueue(int data){
            node *newNode = new node(data);

            if(isEmpty()){
                front = rear = newNode;
                return;
            }
            rear->next = newNode;
            rear = newNode;
        }

        void deQueue(){
            if(isEmpty()){
                cout << "Queue is Empty";
                return;
            }
            node *temp = front;
            front = front->next;
            if(front == nullptr){
                rear = nullptr;
            }
            delete temp;
        }

        int getFront(){
            if (isEmpty())
            {
                cout << "Queue is Empty";
                return -1;
            }
            return front->data;
        }

};
int main()
{
        Queue q;
        q.enQueue(5);
        q.enQueue(6);
        q.enQueue(7);
        q.enQueue(8);
        q.display();

        cout << q.getFront() << endl;

        q.deQueue();
        q.display();

        cout << q.getFront() << endl;

        q.deQueue();
        q.deQueue();
        q.deQueue();
        q.display();
        return 0;
}