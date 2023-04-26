#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{

    public :
        int data;
        node *next;
        node *prev;

        node(int d = 0){
            data = d;
            next = NULL;
            prev = NULL;
        }
};

void display(node* &head){
    node *temp = head;
    while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->next;
    }
    cout << endl;
}
void insertAtHead(node* &head , int data){
        node *newNode = new node(data);

        if(head == NULL){
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode ;
        head = newNode;  
}
void insertAtTail(node* &head , int data){
        node *newNode = new node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode; 
}
void insertAtPos(node* &head , int data , int pos){
        node *newNode = new node(data);
        if(pos == 0){
            insertAtHead(head , data);
            return;
        }
        node *temp = head;
        int index = 0;
        while(index < pos - 1){
            temp = temp->next;
            index++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
} 
void deleteAtHead(node* &head){
    if(head == NULL){
            return;
    }
    node *temp = head;
    temp = temp->next;
    temp->prev = NULL;
    head = temp;
}
void deleteAtTail(node* &head){
    if (head == NULL)
    {
            return;
    }
    node *temp = head;
    while(temp->next->next != NULL){
            temp = temp->next;
    }
    temp->next = NULL;
}
void deleteAtIndex(node* &head , int pos){
    if(pos == 0){
            deleteAtHead(head);
            return;
    }
    int index = 0;
    node *temp = head;
    while(index < pos - 1){
            temp = temp->next;
            index++;
    }
    temp->next = temp->next->next;
    temp->next->prev = temp;
}
void searchNode(node* &head, int data){
    node *temp = head;
    int index = 0;
    while(temp->next != NULL){
            if (temp->data == data)
            {
                cout << "Data " << data << " found at index " << index << endl;
            }
            index++;
            temp = temp->next;
    }
} 
void modifyNode(node* &head){
    node* temp = head ;
    int index = 0 , pos , data;
    cout << "Enter the index and data you want to modify : ";
    cin >> pos >> data;
    while(index < pos){
        temp = temp->next ;
        index++;
    }
    temp->data = data;
}
int main()
{
    node* head = NULL ;
    insertAtHead(head , 19);
    insertAtHead(head , 129);
    display(head);
    insertAtTail(head, 21);
    insertAtTail(head, 31);
    insertAtTail(head, 41);
    display(head);
    insertAtPos(head , 36 , 2);
    display(head);
    deleteAtHead(head);
    display(head);
    deleteAtTail(head);
    display(head);
    deleteAtIndex(head , 1);
    display(head);
    searchNode(head , 21);
    modifyNode(head);
    display(head);
    return 0;
}