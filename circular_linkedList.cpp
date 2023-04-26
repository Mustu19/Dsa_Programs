#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int d = 0)
    {
        data = d;
        next = nullptr;
    }
};
void display(node *&head)
{
    node *temp = head;
    if (head == NULL)
    {
        cout << "null" << endl;
    }
    if (head == head->next)
    {
        cout << head->data << " ";
    }
    else
    {
        while (temp->next != head)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    cout << temp->data << " ";
}
void insertAthead(node *&head, int data)
{
    node *newNode = new node(data);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}
void insertAttail(node *&head, int data)
{
    node *newNode = new node(data);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}
void insertAtPos(node *&head, int data, int pos)
{
    node *newNode = new node(data);

    int index = 0;
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    if (pos == 0)
    {
        insertAthead(head, data);
        return;
    }
    node *temp = head;
    while (index < pos - 1)
    {
        temp = temp->next;
        index++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteAtIndex(node *&head, int index)
{
    node *temp = head;
    node *temp2 = head;
    int i = 0;
    while (temp2->next != head)
    {
        temp2 = temp2->next;
        i++;
    }
    if (index == 0)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
    }
    else if (index == i)
    {
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        temp->next = head;
    }
    else
    {
        int in = 0;
        while (in < index - 1)
        {
            temp = temp->next;
            in++;
        }
        temp->next = temp->next->next;
    }
}
int main()
{

    node *head = NULL;
    insertAthead(head, 8);
    insertAthead(head, 7);
    insertAthead(head, 9);
    insertAttail(head, 67);
    insertAtPos(head, 17, 2);
    display(head);

    deleteAtIndex(head, 0);  // head deletion
    deleteAtIndex(head, 1);
    cout << '\n';
    display(head);

    deleteAtIndex(head , 2); // tail deletion
     cout << '\n';
    display(head);
    return 0;
}