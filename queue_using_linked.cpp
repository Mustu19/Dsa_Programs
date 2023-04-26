#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{

    public:
    int data;
    node* next ;

    node(int d){
        data = d;
        next = nullptr ;
    }
};
class Queue{

    node* front ;
    node* back ;
    public :
    Queue(){
        front = nullptr ;
        back = nullptr ;
    }
    void push(int d){
        node* newNode = new node(d);
        if(front == nullptr){
            front = newNode ;
            back = newNode ;
            return ;
        }
        back->next = newNode ;
        back = newNode ;
    }
    void pop(){
        if(front == nullptr){
            cout<<"Queue is empty" <<endl;
            return ;
        }
        front = front->next ;
    }
    int top(){
        if(front == nullptr){
            cout<<"Queue is empty" ;
            return 0;
        }
        return front->data ;
    }
    void display(){
        if(front == nullptr){
            cout<<"Queue is empty" ;
            return ;
        }
        node* temp = front ;
        while(temp!=NULL){
            cout<<temp->data<<" " ;
            temp = temp->next ;
        }
        cout<<endl;
    }
};
int main()
{
    Queue q;
    q.push(17);
    q.push(23);
    q.push(2);
    q.push(45);
    q.push(56);
    q.display();

    q.pop();
    q.pop();
    q.display();

    cout<<q.top() ;
    return 0;
}