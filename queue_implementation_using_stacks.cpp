// #include<iostream>
// #include<stack>
// using namespace std;
// class queue{
    
//      stack<int> s1 , s2 ;
//     public:
//         bool isEmpty(){
//             return s1.empty();
//         }
//         void add(int data){
//             while(!s1.empty()){
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//             s1.push(data);
//             while(!s2.empty()){
//                 s1.push(s2.top());
//                 s2.pop();
//             }
//         }
//         int remove(){
//             if(!isEmpty()){
//                 cout<<"Queue is empty"<<endl;
//                 return -1;
//             }
//             int top = s1.top();
//             s1.pop();
//             return top;
//         }
//         int peek(){
//             if(!isEmpty()){
//                 cout<<"Queue is empty"<<endl;
//                 return -1;
//             }
//             return s1.top();
//         }
// };
// int main()
// {
//     queue q;
//     q.add(5);
//     q.add(3);
//     q.add(2);

//     while(!q.isEmpty()){
//         cout<<q.peek()<<" ";
//         q.remove();
//     }
//     return 0;
// }




#include <iostream>
#include <stack>

using namespace std;

class Queue {
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    void enqueue(int val) {
        // Move all elements from stack2 to stack1
        while (!stack2.empty()) {
            int value = stack2.top();
            stack2.pop();
            stack1.push(value);
        }
        // Push new value onto stack1
        stack1.push(val);
         // Move all elements from stack1 to stack2
        while (!stack1.empty()) {
            int value = stack1.top();
            stack1.pop();
            stack2.push(value);
        }
    }
    int dequeue() {
       
        
        if (stack2.empty()) {
            cout << "Queue is empty." << endl;
            return -1; // or throw an exception
        }
        // Pop top element from stack2 and return it
        int val = stack2.top();
        stack2.pop();
        return val;
    }
};

int main() {
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout << queue.dequeue() << endl; // should print 1
    cout << queue.dequeue() << endl; // should print 2
    cout << queue.dequeue() << endl; // should print 3
    cout << queue.dequeue() << endl; // should print "Queue is empty." and return -1
    return 0;
}
