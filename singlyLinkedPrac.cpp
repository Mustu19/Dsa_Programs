#include<iostream>
using namespace std;

class node{

    public:
    int value ;
    node* next;

    node(int d){
        value = d ;
        next = NULL;
    }
};
void insertAtHead(node* &head , int n)
{
    node* node1 = new node(n);
    node1->next = head ;
    head = node1 ;
}
void insertAtTail(node* &tail , int n)
{
    node* node1 = new node(n);
    tail->next = node1 ;
    tail = tail->next ;
}
void insertAfterNode(node* givenNode, int x)
{
    node* newNode = new node(x);
    newNode->next = givenNode->next;
    givenNode->next = newNode;
}
void display(node* &head){
    node* temp = head ;
    while(temp!=NULL){
        cout<<temp->value;
        temp = temp->next;
    }
}

bool search(node* head , int key){
    node* temp = head; 
    while (temp!=NULL)
    {
        if(temp->value == key){
            return true; 
        }
        temp = temp->next ; 
    }
    return false; 
    
}
int main()
{
    node* node1 = new node(5) ;
    insertAtHead(node1 , 10) ;
    display(node1);
    insertAtTail(node1 , 35);
    display(node1);
    cout<<search(node1,35);
    return 0;
}