// circular queue implementation using array

#include<iostream>
using namespace std;
class queue{

    int size;
    int *arr;
    int rear;
    int front ;

    public:
    queue(int s){
        rear = -1 ;
        front = -1 ;
        size = s ;
        arr = new int[size] ;
    }
    bool isEmpty(){
        return rear == -1 && front==-1;
    }
    bool isFull(){
        return (rear+1)%size == front ;
    }
    void add(int d){
        if(isFull()){
            cout<<"queue is full";
            return;
        }
        // first element add
        if(front == -1){
            front = 0;
        }
        rear = (rear+1) % size ;
        arr[rear] = d ;
    }
    int remove(){
        if(isEmpty()){
            cout<<"Queue is Empty" ;
        }
        int res = arr[front] ;
        if(rear == front){
            rear == front == -1 ;
        }
        else{
            front = (front+1) % size ;
        }
        return res;
    }
    int peek(){
        if(isEmpty()){
            cout<<"Queue is Empty" ;
            return -1;
        }
        return arr[front];
    }
};
int main()
{
 queue q(5);
 q.add(4);
 q.add(23);
 q.add(67);
while(!q.isEmpty()){
    cout<<q.peek()<<" " ;
     q.remove();
}

// cout<<q.remove();
// q.add(37);
 return 0;
}