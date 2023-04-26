// queue implementation using array

#include<iostream>
using namespace std;
class queue{

    int arr[5] ;
    int rear;

    public:
    queue(){
        rear = -1 ;
    }
    void display(){
        for (int i = 0; i <= rear; i++)
        {
            cout<<arr[i]<<" " ;
        }
    }
    bool isEmpty(){
        return rear == -1;
    }
    void add(int d){
        int size = 5 ;
        if(size-1 == rear){
            cout<<"queue is full";
            return;
        }
        rear++;
        arr[rear] = d ;
    }
    int remove(){
        if(isEmpty()){
            cout<<"Queue is Empty" ;
        }
        int front = arr[0] ;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = arr[i+1] ;
        }
        rear--;
        return front;
    }
    int peek(){
        if(isEmpty()){
            cout<<"Queue is Empty" ;
            return -1;
        }
        return arr[0];
    }
};
int main()
{
 queue q;
 q.add(4);
 q.add(23);
 q.add(67);
 q.display();

cout<<q.peek();
cout<<q.remove();
q.display();
 
 return 0;
}