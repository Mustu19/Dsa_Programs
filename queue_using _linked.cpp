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
class queue{

    node* front ;
    node* back ;

    queue(){
        front = nullptr ;
        back = nullptr ;
    }
    void push(int d){
        node* newNode = new node(d);
        if(front == nullptr){
            front = newNode ;
            back = newNode ;
        }
        back->next = newNode ;
        back = newNode ;
    }
    void pop(){
        if(front == nullptr){
            cout<<"Queue is empty" ;
            return ;
        }
        front = front->next ;
    }
    int top(){
        if(front == nullptr){
            cout<<"Queue is empty" ;
            return ;
        }
        return front->data ;
    }
    void display(){
        if(front == nullptr){
            cout<<"Queue is empty" ;
            return ;
        }
        while(front->next!=NULL){
            cout<<front->data<<" " ;
            front = front->next ;
        }
    }
};
int main()
{
    queue q;
    q.push(17);
    q.push(23);
    q.display();
    return 0;
}