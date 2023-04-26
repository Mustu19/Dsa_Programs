#include<iostream>
using namespace std;
class node{
    public : 
        int data ;
        node* next ;
    node(int d){
        data = d ;
        next = NULL ;
    }
    ~node(){
        int value = this->data ;
        if(this->next != NULL){
            delete next ;
            this->next = NULL ;
        }
        cout<<"memory is free for node with data "<<value<< endl;
    }
};  
void insertTohead(node* &head , int d){
    node* temp = new node(d) ;
    temp->next = head ;
    head = temp  ;
}
void insertToTail(node* &tail , int d){
    node* temp = new node(d) ;
    tail->next = temp ;
    tail = tail->next ;
}
void insertAtPosition(node* &tail , node* &head , int position , int d){
    
    if(position == 1){
        insertTohead(head , d) ;
        return ;
    }
    node* temp = head ;
    int cnt = 1 ;
    while(cnt < position - 1){
        temp = temp->next ;
        cnt++ ;        
    }
    if(temp->next == NULL){
        insertToTail(tail, d);
        return ;
    }
    node* node2 = new node(d);
    node2->next = temp->next ;
    temp->next = node2 ;
}

void deleteNode(int position , node* &head){
    //deleting first node
    if(position == 1){
        node* temp = head ;
        head = head->next  ;
        //memory free start ode
        temp->next = NULL ;
        delete temp ;
    }else{
        // deleting middle or last node
        node* curr = head ;
        node* prev = NULL ;

        int cnt = 1; 
        while(cnt <= position){
            prev = curr ;
            curr = curr->next ;
            cnt++ ;
        }
        prev->next = curr->next ;
        curr->next = NULL ;
        delete curr ;
    }
}
void printList(node* &head){
    node* temp = head ;
    while(temp != NULL){
        cout<<temp->data;
        temp = temp->next ;
    }
    cout<<" " ;
}
int main()
{
    node* node1 = new node(5);
    node* head = node1 ;
    insertTohead(head , 10);
    printList(head);
    node* tail = head ;
    insertToTail(tail , 15);
    printList(head);
    insertAtPosition(tail ,head , 3 , 35);
    printList(head);

    deleteNode(1 , head );
    printList(head);
    return 0;
}