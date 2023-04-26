#include<iostream>
// #include<bits/stdc++.h>
using namespace std;
class queue{
    int rear ;
    int arr[5] ;
    public :
    queue(){
        rear = -1 ;
    }
    void push(int d){
        int size = 5 ;
        if(size-1 == rear){
            cout<<"FULL"<<endl;
            return ;
        }
        rear++;
        arr[rear] = d ;
    }
    bool isEmpty(){
        return rear==-1;
    }
    int pop(){
        if(isEmpty()){
            cout<<"EMPTY"<<endl;
            return -1;
        }
        int front = arr[0] ;
        for(int i = 0 ; i < 5 ; i++){
            arr[i] = arr[i+1] ;
        }
        rear-- ;
        return front ;
    }
    int peek(){
        if(isEmpty()){
            cout<<"EMPTY"<<endl;
            return -1;
        }
        return arr[0] ;
    }
    void display(){
        for (int i = 0; i <= rear; i++)
        {
            cout<<arr[i]<<" " ;
        }
        cout<<endl;
        
    }
};
int main()
{
    queue q ;
    q.push(5);
    q.push(6);
    q.push(7);
    q.display();
    return 0;
}